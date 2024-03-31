#pragma once

#include <random>
#include <ctime>
#include "Figure.h"

enum TypeFigure
{
	I,
	J,
	L,
	O, 
	S,
	T,
	Z
};

class FigureGenerator
{
private:
	std::vector<Color> colorDatabase;

public:
	FigureGenerator();

	Figure getNewFigure();
};

