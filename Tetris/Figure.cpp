#include "Figure.h"

Figure::Figure()
{
	figure = {};
	centerRotation = { 0, 0 };
	isCanRotate = false;
}

void Figure::setFigure(const std::vector<Coordinates> figure, 
							const Coordinates centerPoint)
{
	this->centerRotation = centerPoint;
	this->figure = figure;
}

void Figure::setIsCanRotate(const bool value)
{
	isCanRotate = value;
}

void Figure::setColor(const Color color)
{
	this->color = color;
}

Color Figure::getColor()
{
	return color;
}

void Figure::moveDown()
{
	for (auto &cell : figure) {
		cell.y += 1;
	}
	centerRotation.y += 1;
}

void Figure::moveUp()
{
	for (auto& cell : figure) {
		cell.y -= 1;
	}
	centerRotation.y -= 1;
}

void Figure::moveLeft()
{
	for (auto &cell: figure) {
		cell.x -= 1;
	}
	centerRotation.x -= 1;
}

void Figure::moveRight()
{
	for (auto& cell : figure) {
		cell.x += 1;
	}
	centerRotation.x += 1;
}

void Figure::rotate()
{
	if (!isCanRotate) {
		return;
	}

	for (size_t i = 0; i < figure.size(); i++) {
		Coordinates currentCoordinatesRelativeCenter = { figure[i].x - centerRotation.x,
														figure[i].y - centerRotation.y };
		Coordinates newCoordinatesRelativeCenter = { -currentCoordinatesRelativeCenter.y,
													currentCoordinatesRelativeCenter.x };
		figure[i].x += newCoordinatesRelativeCenter.x - currentCoordinatesRelativeCenter.x;
		figure[i].y += newCoordinatesRelativeCenter.y - currentCoordinatesRelativeCenter.y;
	}
}

std::vector<Coordinates> Figure::getVectorCoordinates()
{
	return figure;
}

Figure Figure::deleteLine(size_t indexLine)
{
	bool isCellsAboveDeliteLine = false;
	bool isCellsBelowDeliteLine = false;
	long long size = figure.size();
	Figure newFigure;
	for (long long i = 0; i < size; i++) {
		if (figure[i].y == indexLine) {
			figure.erase(figure.begin() + i);
			i--;
			size--;
		} else if (figure[i].y < indexLine) {
			isCellsAboveDeliteLine = true;
		} else if (figure[i].y > indexLine) {
			isCellsBelowDeliteLine = true;
		}
	}
	if (isCellsAboveDeliteLine && isCellsBelowDeliteLine) {
		size = figure.size();
		std::vector<Coordinates> tmp;
		for (long long i = 0; i < size; i++) {
			if (figure[i].y > indexLine) {
				tmp.push_back(figure[i]);
				figure.erase(figure.begin() + i);
				i--;
				size--;
			}
		}
		newFigure.setFigure(tmp, tmp[0]);
	}
	return newFigure;
}

bool Figure::isEmptyFigure()
{
	return figure.empty();
}


