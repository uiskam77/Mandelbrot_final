#pragma once

#include "Point.h"

#include <SDL.h>
#include <vector>
/**
klasa abstrakcyjna po kt�rej dzieczyczy PointDrawerGB oraz PointDrawerRGB (polimorfizm)
*/

class PointDrawer
{
public:
	PointDrawer()
	{}
	virtual ~PointDrawer() = default;

	// rysuje punkty
	virtual void drawPoints(const std::vector<Point>& points, SDL_Renderer* renderer) = 0;
};

