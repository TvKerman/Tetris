#pragma once

#include <vector>
#include <iostream>
#include "Cell.h"
#include "Coordinates.h"

#define FIELD_WIDTH_SIZE 10
#define FIELD_HEIGHT_SIZE 20

class PlayingField
{
private:
	size_t countRows;
	size_t countColumns;
	std::vector<std::vector<Cell>> field;

	bool isValidPositionForFigure(const std::vector<Coordinates>& coordinates);

public:
	PlayingField();

	bool isFullLine(size_t indexLine);

	std::vector<size_t> clearLine();

	Cell getCell(Coordinates point) const;

	Cell& getRefCell(Coordinates point);

	bool addNewFigureToTheField(const std::vector<Coordinates>& coordinates,
								const Color colorFigure);

	//void updateField();

	void printField();

	bool updateFigureCoordinates(
		const std::vector<Coordinates> &currentCoordinates,
		const std::vector<Coordinates> &newCoordinates);

};

