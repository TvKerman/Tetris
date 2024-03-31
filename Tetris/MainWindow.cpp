#include "MainWindow.h"

void MainWindow::drawScore()
{
	sf::Font font;
	font.loadFromFile("NewCountry.ttf");
	sf::Text text("", font, 25);
	text.setString(score);
	text.setFillColor(sf::Color::Black);
	//text.setStyle(sf::Text::Bold);
	text.setPosition(SCORE_POS_X, SCORE_POS_Y);
	mainWindow.draw(text);
}

void MainWindow::drawNextFigure()
{
	sf::Font font;
	font.loadFromFile("NewCountry.ttf");
	sf::Text text("Next;", font, 25);
	text.setFillColor(sf::Color::Black);
	//text.setStyle(sf::Text::Bold);
	text.setPosition(NEXT_TEXT_POS_X, NEXT_TEXT_POS_Y);
	mainWindow.draw(text);

	sf::RectangleShape background(sf::Vector2f(4.1 * (WIDTH_CELL + CONTOUR_THICKNESS) + CONTOUR_THICKNESS,
											   4.1 * (HEIGHT_CELL + CONTOUR_THICKNESS) + CONTOUR_THICKNESS));
	background.setPosition(sf::Vector2f(NEXT_POS_X, NEXT_POS_Y));
	background.setFillColor(sf::Color::White);
	background.setOutlineThickness(CONTOUR_THICKNESS);
	background.setOutlineColor(sf::Color::Black);
	mainWindow.draw(background);

	std::vector<size_t> valueColor = nextFigure.getColor().getColor();
	std::vector<Coordinates> tmp = nextFigure.getVectorCoordinates();
	int maxX = 0;
	int maxY = 0;
	for (auto& cell : tmp) {
		if (cell.x > maxX) {
			maxX = cell.x;
		}
		if (cell.y > maxY) {
			maxY = cell.y;
		}
	}
	float startX;
	float startY;
	if (maxX == 3) {
		startX = START1_POS_NEXT_X;
	}
	else if (maxX == 2) {
		startX = START2_POS_NEXT_X;
	}
	else if (maxX == 1) {
		startX = START3_POS_NEXT_X;
	}
	else {
		startX = START4_POS_NEXT_X;
	}

	if (maxY == 3) {
		startY = START1_POS_NEXT_Y;
	}
	else if (maxY == 2) {
		startY = START2_POS_NEXT_Y;
	}
	else if (maxY == 1) {
		startY = START3_POS_NEXT_Y;
	}
	else {
		startY = START4_POS_NEXT_Y;
	}

	for (auto& coordinates : tmp) {
		sf::RectangleShape cell(sf::Vector2f(WIDTH_CELL, HEIGHT_CELL));
		cell.setPosition(sf::Vector2f(startX + (WIDTH_CELL + CONTOUR_THICKNESS) * coordinates.x,
									  startY + (HEIGHT_CELL + CONTOUR_THICKNESS) * coordinates.y));
		cell.setFillColor(sf::Color(valueColor[0], valueColor[1], valueColor[2]));
		cell.setOutlineThickness(CONTOUR_THICKNESS);
		cell.setOutlineColor(sf::Color::Black);
		mainWindow.draw(cell);
	}
}

void MainWindow::drawGameOver()
{
	sf::Font font;
	font.loadFromFile("NewCountry.ttf");
	sf::Text text("Game over", font, 35);
	text.setFillColor(sf::Color::Black);
	//text.setStyle(sf::Text::Bold);
	text.setPosition(GAME_OVER_POS_X, GAME_OVER_POS_Y);
	mainWindow.draw(text);
}

MainWindow::MainWindow()
{
	widthWindow = WIDTH_WINDOW;
	heightWindow = HEIGHT_WINDOW;
	mainWindow.create(sf::VideoMode(widthWindow, heightWindow), "Tetris",
		sf::Style::Titlebar | sf::Style::Close);
	mainWindow.setVerticalSyncEnabled(true);

}

void MainWindow::setScore(size_t score)
{
	this->score = std::string("Score; ") + std::to_string(score);
}

void MainWindow::setStateField(const PlayingField& field)
{
	this->field.setNewState(field);
}

void MainWindow::setNextFigure(const Figure figure)
{
	nextFigure = figure;
	std::vector<Coordinates> tmp = nextFigure.getVectorCoordinates();
	Coordinates min = {7, 7};
	for (auto cell : tmp) {
		if (cell.x < min.x) {
			min.x = cell.x;
		} 
		if (cell.y < min.y) {
			min.y = cell.y;
		}
	}
	Coordinates max = {0, 0};
	for (auto& cell : tmp) {
		cell.x -= min.x;
		cell.y -= min.y;
		//if (cell.x > max.x) {
		//	max.x = cell.x;
		//}
		//if (cell.y > max.y) {
		//	max.y = cell.y;
		//}
	}
	//Coordinates delta = { 0, 0 };
	//if (max.x < 3) {
	//	delta.x = 1;
	//}
	//if (max.y < 2) {
	//	delta.y = 1;
	//}
	//for (auto &cell: tmp) {
	//	cell.x += delta.x;
	//	cell.y += delta.y;
	//}
	nextFigure.setFigure(tmp, tmp[0]);
}

void MainWindow::setGameOver(bool value)
{
	isGameOver = value;
}

void MainWindow::show()
{
	mainWindow.clear();
	sf::RectangleShape background(sf::Vector2f(WIDTH_WINDOW, HEIGHT_WINDOW));
	background.setFillColor(sf::Color::White);
	mainWindow.draw(background);
	drawScore();
	drawNextFigure();
	if (isGameOver) {
		drawGameOver();
	}
	field.show(mainWindow);
	
	mainWindow.display();
}

void MainWindow::updateWindow()
{
	sf::Event event;
	while (mainWindow.pollEvent(event))
	{
		// пользователь попытался закрыть окно: мы закрываем окно
		if (event.type == sf::Event::Closed)
			mainWindow.close();
	}
}

bool MainWindow::isOpen()
{
	return mainWindow.isOpen();
}
