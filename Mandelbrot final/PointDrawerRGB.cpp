#include "PointDrawerRGB.h"

#include "Scaler.h"

#include <SDL.h>
/**
rysuje punkty w kolorze
*/

void PointDrawerRGB::drawPoints(const std::vector<Point>& points, SDL_Renderer* renderer)
{
	for (const auto& point : points)
	{
		double bright = point.value;
		double red{ map(bright * bright, 0, 6502, 0, 255) };
		double green{ bright };
		double blue{ map(sqrt(bright), 0, sqrt(255), 0, 255) };
		SDL_SetRenderDrawColor(renderer, red, green, blue, bright);
		SDL_RenderDrawPoint(renderer, point.x, point.y);
	}
}
