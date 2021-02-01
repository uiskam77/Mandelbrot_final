#pragma once

#include "PointDrawer.h"

class PointDrawerRGB : public PointDrawer
{
public:
	PointDrawerRGB() : PointDrawer()
	{}

	void drawPoints(const std::vector<Point>& points, SDL_Renderer* renderer) override;
};

