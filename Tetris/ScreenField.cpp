#include "ScreenField.h"

ScreenField::ScreenField()
{
	startX = START_POS_X;
	startY = START_POS_Y;
	widthCell = WIDTH_CELL;
	heightCell = HEIGHT_CELL;
	countRows = FIELD_HEIGHT_SIZE;
	countColumns = FIELD_WIDTH_SIZE;
	field = std::vector<std::vector<Color>>(countRows, 
		std::vector<Color>(countColumns, Color()));
}

void ScreenField::show(sf::RenderWindow& window)
{
	for (size_t i = 0; i < countRows; i++) {
		for (size_t j = 0; j < countColumns; j++) {
			sf::RectangleShape cell(sf::Vector2f(widthCell, heightCell));
			cell.setPosition(sf::Vector2f(startX + j * (widthCell + CONTOUR_THICKNESS),
										  startY + i * (heightCell + CONTOUR_THICKNESS)));
			std::vector<size_t> valueColor = field[i][j].getColor();
			cell.setFillColor(sf::Color(valueColor[0], valueColor[1], valueColor[2]));
			cell.setOutlineThickness(CONTOUR_THICKNESS);
			cell.setOutlineColor(sf::Color(0, 0, 0));
			window.draw(cell);
		}
	}
}

void ScreenField::setNewState(const PlayingField& field)
{
	for (size_t i = 0; i < countRows; i++) {
		for (size_t j = 0; j < countColumns; j++) {
			Coordinates pos = { static_cast<int>(j), static_cast<int>(i) };
			this->field[i][j] = field.getCell(pos).getColor();
		}
	}
}
