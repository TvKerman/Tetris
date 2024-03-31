#include "Cell.h"

Cell::Cell()
{
	isFree = true;
	color = Color();
}

bool Cell::getFree()
{
	return isFree;
}

void Cell::setFree(bool state)
{
	isFree = state;
}

Color Cell::getColor()
{
	return color;
}

void Cell::setColor(Color color)
{
	this->color = color;
}
