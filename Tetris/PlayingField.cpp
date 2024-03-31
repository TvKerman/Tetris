#include "PlayingField.h"

bool PlayingField::isValidPositionForFigure(const std::vector<Coordinates>& coordinates)
{
	for (size_t i = 0; i < coordinates.size(); i++) {
		try
		{
			if (!getCell(coordinates[i]).getFree()) {
				return false;
			}
		}
		catch (const std::exception&)
		{
			return false;
		}
	}
	return true;
}

PlayingField::PlayingField()
{
	countRows = FIELD_HEIGHT_SIZE;
	countColumns = FIELD_WIDTH_SIZE;
	field = std::vector<std::vector<Cell>>(countRows, std::vector<Cell>(countColumns));
}

bool PlayingField::isFullLine(size_t indexLine)
{
	for (auto cell : field[indexLine]) {
		if (cell.getFree()) {
			return false;
		}
	}

	return true;
}

std::vector<size_t> PlayingField::clearLine()
{
	std::vector<size_t> result;
	for (size_t i = 0; i < countRows; i++) {
		if (isFullLine(i)) {
			result.push_back(i);
			for (auto &cell: field[i]) {
				cell.setFree(true);
				cell.setColor(Color());
			}
		}
	}
	return result;
}

Cell PlayingField::getCell(Coordinates point) const
{
	if (point.x >= countColumns || point.x < 0 || 
		point.y >= countRows || point.y < 0) {
		throw std::exception();
	}
	return field[point.y][point.x];
}

Cell& PlayingField::getRefCell(Coordinates point)
{
	// TODO: вставьте здесь оператор return
	if (point.x >= countColumns || point.x < 0 ||
		point.y >= countRows || point.y < 0) {
		throw std::exception();
	}
	return field[point.y][point.x];
}

bool PlayingField::addNewFigureToTheField(const std::vector<Coordinates>& coordinates, const Color colorFigure)
{
	if (!isValidPositionForFigure(coordinates)) {
		return false;
	}
	for (auto& point : coordinates) {
		getRefCell(point).setFree(false);
		getRefCell(point).setColor(colorFigure);
	}
	return true;
}

void PlayingField::printField()
{
	for (size_t i = 0; i < countRows; i++) {
		for (size_t j = 0; j < countColumns; j++) {
			bool isFree = field[i][j].getFree();
			if (!isFree) {
				std::cout << "1 ";
			} else {
				std::cout << "- ";
			}
		}
		std::cout << "\n";
	}
}

bool PlayingField::updateFigureCoordinates(const std::vector<Coordinates>& currentCoordinates,
											const std::vector<Coordinates>& newCoordinates)
{
	Color figureColor = getRefCell(currentCoordinates[0]).getColor();
	for (auto& point : currentCoordinates) {
		getRefCell(point).setFree(true);
		getRefCell(point).setColor(Color());
	}
	if (!isValidPositionForFigure(newCoordinates)) {
		for (auto& point : currentCoordinates) {
			getRefCell(point).setFree(false);
			getRefCell(point).setColor(figureColor);
		}
		return false;
	}
	if (currentCoordinates.empty()) {
		return false;
	}

	for (auto& point : newCoordinates) {
		getRefCell(point).setFree(false);
		getRefCell(point).setColor(figureColor);
	}

	return true;
}
