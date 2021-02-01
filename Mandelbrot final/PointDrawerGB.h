#pragma once

#include "PointDrawer.h"

class PointDrawerGB : public PointDrawer
{
public:
	void drawPoints(const std::vector<Point>& points, SDL_Renderer* renderer) override;
};

