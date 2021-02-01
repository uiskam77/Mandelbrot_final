#include "PointDrawerGB.h"

#include <SDL.h>
/**
rysyje punkty w kolorze (czarno-bia³e)
*/

void PointDrawerGB::drawPoints(const std::vector<Point>& points, SDL_Renderer* renderer)
{
	for (const auto& point : points)
	{
		double bright = point.value;
		SDL_SetRenderDrawColor(renderer, bright, bright, bright, 255);
		SDL_RenderDrawPoint(renderer, point.x, point.y);
	}
}

