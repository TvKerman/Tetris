#pragma once

#include "Color.h"

class Cell
{
private:
	bool isFree;
	Color color;

public:
	Cell();

	bool getFree();

	void setFree(bool state);

	Color getColor();

	void setColor(Color color);
};

