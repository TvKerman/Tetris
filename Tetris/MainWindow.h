#pragma once

#include <SFML/Graphics.hpp>
#include "ScreenField.h"
#include "PlayingField.h"
#include "Figure.h"

#define WIDTH_WINDOW 510
#define HEIGHT_WINDOW 856
#define SCORE_POS_X 10
#define SCORE_POS_Y 10
#define NEXT_TEXT_POS_X 370
#define NEXT_TEXT_POS_Y 10
#define NEXT_POS_X 345
#define NEXT_POS_Y 40
#define START1_POS_NEXT_X 349
#define START1_POS_NEXT_Y 44
#define START2_POS_NEXT_X 366
#define START2_POS_NEXT_Y 61
#define START3_POS_NEXT_X 382
#define START3_POS_NEXT_Y 77
#define START4_POS_NEXT_X 399
#define START4_POS_NEXT_Y 94
#define GAME_OVER_POS_X 50
#define GAME_OVER_POS_Y 100


class MainWindow
{
private:

	size_t widthWindow;
	size_t heightWindow;
	sf::RenderWindow mainWindow;
	std::string score;
	ScreenField field;
	Figure nextFigure;
	bool isGameOver = false;

	void drawScore();

	void drawNextFigure();

	void drawGameOver();

public:
	MainWindow();

	void setScore(size_t score);

	void setStateField(const PlayingField& field);

	void setNextFigure(const Figure figure);

	void setGameOver(bool value);

	void show();

	void updateWindow();

	bool isOpen();
};
