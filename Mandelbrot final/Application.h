#pragma once

#include "Point.h"

#include <SDL.h>
#include <vector>
#include <memory>

class PointDrawer;
/**
Mo¿emy w tym miejscu zmieniaæ parametry programu 

*/
class Application
{
public:
	Application();
	~Application();

	void increaseParamters(int count);
	std::vector<Point> createAndRescalePoints();
	std::vector<Point> createpoints();
	bool isQuit();
	void run();

private:
	std::unique_ptr<PointDrawer> drawer;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;

	double min{ -1.84 };  // zakres obszaru generowanych punktówqqq
	double max{ 2.0 };   // zakres obszaru generowanych punktów
	int maxIterations{ 100 }; // liczba wykonywanych iteracji
	double factory{ 0.0}; // przybli¿enie generowanego fraktala (0 - przybli¿anie wy³¹czone)
	const int width{ 750 }; // szerokoœæ okna programu
	const int high{ 950 }; // wysokoœæ okna programu
};

