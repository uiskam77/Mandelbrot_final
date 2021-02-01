#include "Application.h"

#include "Complex.h"
#include "PointDrawerGB.h"
#include "PointDrawerRGB.h"
#include "Scaler.h"

#include <algorithm>
#include <iostream>
#include <Windows.h>

Application::Application() :
	 drawer(new PointDrawerGB()) // PointDrawerGB - czarno biale, PointDrawerRGB - kolorowe
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(width, high, 0, &window, &renderer);
	SDL_RenderSetLogicalSize(renderer, width, high);
}

Application::~Application() = default;

/**
* funkcja increaseParameters zawiera parametry w celu uzyskania efektu przybliżania
*/

void Application::increaseParamters(int count)
{
	max -= 0.1 * factory;
	min += 0.15 * factory;
	factory *= 0.9349;
	maxIterations += 5;
	if (count > 30)
	{
		maxIterations *= 1.02;
	}
}
/**
createpoints() tworzy punkty zbioruq
*/

std::vector<Point> Application::createpoints()
{
	std::vector<Point> points;
	for (int x = 0; x < width; ++x)
	{
		for (int y = 0; y < high; ++y)
		{
			auto a = map(x, 0, width, min, max); // rzeczywisty
			auto b = map(y, 0, high, min, max); // urojony
			Complex complexNumber(a, b);
			auto startedComplexNumber = complexNumber;
			Point point(x, y);
			while (complexNumber() && point < maxIterations) // zwiekszaj wartosc punktu dopóki |complexNumber| < 2 i nie osiagnie max
			{
				auto newComplexNumber = complexNumber * complexNumber;
				complexNumber = newComplexNumber + startedComplexNumber;
				++point;
			}
			points.emplace_back(point);
		}
	}
	return points;
}
/**
createAndRescalePoints tworzy punkty i przeskalowuje je
*/

std::vector<Point> Application::createAndRescalePoints()
{
	std::vector<Point> points = createpoints();
	std::replace_if(points.begin(), points.end(), [&](Point& point){ return point == maxIterations; }, 0); // przypisz wartosc 0 do punktow co maja max
	std::replace_if(points.begin(), points.end(), [](Point& point){ return point < 20; }, 0); // przypisz wartosc 0 do punktow co maja < 20
	auto scalePixel = [&](Point& point)
	{
		point = map(point.value, 0, maxIterations, 0, 255);
	};
	std::for_each(points.begin(), points.end(), scalePixel); // przeskaluj wszystkie
	return points;
}
/**
Sprawdzenie  czy nie występują warunki zakończenia programu np, użytkownik nie nacisk q
*/

bool Application::isQuit()
{
	if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
	{
		return true;
	}
	if (GetKeyState('Q') & 0x8000)
	{
		return true;
	}
	return false;
}
/**
funkcja uruchomienia programu
*/

void Application::run()
{
	try
	{
		int count = 0;
		while (!isQuit()) // dopóki uzytkownik nie "wyjdzie" (np naciskajac q)
		{
			SDL_RenderPresent(renderer);
			increaseParamters(count); // "zoomowanie" - przyblizanie
			drawer->drawPoints(createAndRescalePoints(), renderer); // tworzymy punkty a nastepnie rysujemy je
			++count;
		}
	}
	catch (const std::runtime_error& error)
	{
		std::cout << error.what() << std::endl; // lapiemy wyjatek jak dzielnie przez zero
	}
	catch (const std::exception& error)
	{
		std::cout << "Unexpected error " << error.what() << std::endl; // nie oczekujemy innych wyjatkow ale sprawdzamy do pewnosci
	}
}