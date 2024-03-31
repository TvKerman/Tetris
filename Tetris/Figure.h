#pragma once

#include <vector>
#include "Coordinates.h"
#include "Color.h"

class Figure
{
private:
	bool isCanRotate;
	Coordinates centerRotation;
	std::vector<Coordinates> figure;
	Color color;

public:
	Figure();

	void setFigure(const std::vector<Coordinates> figure, const Coordinates centerPoint);

	void setIsCanRotate(const bool value);

	void setColor(const Color color);

	Color getColor();

	void moveDown();

	void moveUp();

	void moveLeft();

	void moveRight();

	void rotate();

	std::vector<Coordinates> getVectorCoordinates();

	Figure deleteLine(size_t indexLine);

	bool isEmptyFigure();
};

