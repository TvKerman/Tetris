#include "FigureGenerator.h"

FigureGenerator::FigureGenerator()
{
	srand(time(0));
	colorDatabase = {
		Color(249, 255, 3),
		Color(0, 227, 253),
		Color(245, 2, 0),
		Color(104, 180, 34),
		Color(254, 140, 3),
		Color(255, 83, 189),
		Color(64, 0, 255)
	};
}

Figure FigureGenerator::getNewFigure()
{
	TypeFigure type = static_cast<TypeFigure>(std::rand() % 7);
	size_t indexColor = std::rand() % colorDatabase.size();
	Figure newFigure;
	newFigure.setColor(colorDatabase[indexColor]);
	newFigure.setIsCanRotate(true);
	switch (type)
	{
	case I:
		newFigure.setFigure({ {3, 0}, {4, 0}, {5, 0}, {6, 0} }, { 4, 0 });
		break;
	case J:
		newFigure.setFigure({ {5, 0}, {5, 1}, {4, 2}, {5, 2} }, { 5, 1 });
		break;
	case L:
		newFigure.setFigure({ {4, 0}, {4, 1}, {4, 2}, {5, 2} }, { 4, 1 });
		break;
	case O:
		newFigure.setFigure({ {4, 0}, {5, 0}, {4, 1}, {5, 1} }, { 4, 0 });
		newFigure.setIsCanRotate(false);
		break;
	case S:
		newFigure.setFigure({ {5, 0}, {6, 0}, {4, 1}, {5, 1} }, { 5, 1 });
		break;
	case T:
		newFigure.setFigure({ {4, 0}, {5, 0}, {6, 0}, {5, 1} }, { 5, 0 });
		break;
	case Z:
		newFigure.setFigure({ {4, 0}, {5, 0}, {5, 1}, {6, 1} }, { 5, 1 });
		break;
	default:
		newFigure.setIsCanRotate(false);
		break;
	}
	return newFigure;
}
