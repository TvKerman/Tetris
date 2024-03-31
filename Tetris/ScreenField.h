#pragma once

#include "PlayingField.h"
#include <SFML/Graphics.hpp>

#define START_POS_X 10
#define START_POS_Y 190
#define WIDTH_CELL 30
#define HEIGHT_CELL 30
#define CONTOUR_THICKNESS 3


class ScreenField
{
private:
	size_t startX;
	size_t startY;
	size_t widthCell;
	size_t heightCell;
	size_t countRows;
	size_t countColumns;
	std::vector<std::vector<Color>> field;

public:

	ScreenField();

	void show(sf::RenderWindow &window);

	void setNewState(const PlayingField &field);

};

