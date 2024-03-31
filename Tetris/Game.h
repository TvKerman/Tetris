#pragma once

#include "PlayingField.h"
#include "Figure.h"
#include "FigureGenerator.h"
#include "MainWindow.h"
#include "Timer.h"

#define SCORE_PER_LINE 100
#define DROP_TIME_PER_CELL 900.0
#define MINIMUM_TIME_BETWEEN_TAPS 200.0

class Game
{
private:
	PlayingField field;
	FigureGenerator generator;
	Figure currentFigure;
	Figure nextFigure;
	std::vector<Figure> fallenFigure;
	size_t score;
	bool isCanMoveDownCurrentFigure;
	bool isGameOver;
	MainWindow window;
	Timer timer;

	Timer tapSpaceTimer;
	Timer tapLeftTimer;
	Timer tapRightTimer;
	Timer tapDownTimer;

	bool moveFigureDown(Figure &figure);

	bool moveFigureBottom(Figure &figure);

	void restart();

	void moveFigureRight();

	void moveFigureLeft();

	bool moveFigureDown();

	void moveFigureBottom();

	void rotateFigure();

	bool GameOver();

public:
	Game();

	void update();

	void show();

	bool isOpenWindow();
};

