#include "Game.h"

bool Game::moveFigureDown(Figure& figure)
{
	std::vector<Coordinates> currentCoordinates = figure.getVectorCoordinates();
	figure.moveDown();
	std::vector<Coordinates> newCoordinates = figure.getVectorCoordinates();
	bool isMoveDown = field.updateFigureCoordinates(currentCoordinates, newCoordinates);
	if (!isMoveDown) {
		figure.moveUp();
	}
	return isMoveDown;
}

bool Game::moveFigureBottom(Figure& figure)
{
	bool isCanMoveDown = moveFigureDown(figure);
	bool result = isCanMoveDown;
	while (isCanMoveDown) {
		isCanMoveDown = moveFigureDown(figure);
	}
	return result;
}

Game::Game()
{
	//field = PlayingField();
	//generator = FigureGenerator();
	currentFigure = generator.getNewFigure();
	nextFigure = generator.getNewFigure();
	fallenFigure = std::vector<Figure>();
	score = 0;
	field.addNewFigureToTheField(currentFigure.getVectorCoordinates(), currentFigure.getColor());
	isCanMoveDownCurrentFigure = true;
	isGameOver = false;
	window.setScore(score);
	window.setStateField(field);
	window.setNextFigure(nextFigure);
	timer.restart();
}

void Game::update()
{
	window.updateWindow();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)
		&& timer.getCurrentTime() > MINIMUM_TIME_BETWEEN_TAPS) {
		restart();
		return;
	}

	if (isGameOver) {
		return;
	}
	bool isMoveDown = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && 
		tapSpaceTimer.getCurrentTime() > MINIMUM_TIME_BETWEEN_TAPS) {
		tapSpaceTimer.restart();
		rotateFigure();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
		tapLeftTimer.getCurrentTime() > MINIMUM_TIME_BETWEEN_TAPS) {
		tapLeftTimer.restart();
		moveFigureLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
		tapRightTimer.getCurrentTime() > MINIMUM_TIME_BETWEEN_TAPS) {
		tapRightTimer.restart();
		moveFigureRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
		tapDownTimer.getCurrentTime() > MINIMUM_TIME_BETWEEN_TAPS) {
		tapDownTimer.restart();
		moveFigureBottom();
		isMoveDown = false;
	}


	if (!isCanMoveDownCurrentFigure) {
		currentFigure = nextFigure;
		nextFigure = generator.getNewFigure();
		window.setNextFigure(nextFigure);
		isGameOver = !field.addNewFigureToTheField(currentFigure.getVectorCoordinates(), currentFigure.getColor());
		isCanMoveDownCurrentFigure = true;
		if (isGameOver) {
			window.setGameOver(true);
		}
	}

	// Таймер для отсчёта нужен...
	if (timer.getCurrentTime() > DROP_TIME_PER_CELL || !isMoveDown) {
		timer.restart();
		isMoveDown = moveFigureDown();
	}
	if (!isMoveDown) {
		isCanMoveDownCurrentFigure = false;
		fallenFigure.push_back(currentFigure);
		std::vector<size_t> lineIndex = field.clearLine();
		while (!lineIndex.empty()) {
			score += lineIndex.size() * SCORE_PER_LINE;
			window.setScore(score);
			for (auto index : lineIndex) {
				long long size = static_cast<long long>(fallenFigure.size());
				for (long long i = 0; i < size; i++) {
					Figure pathFigure = fallenFigure[i].deleteLine(index);
					if (!pathFigure.isEmptyFigure()) {
						fallenFigure.push_back(pathFigure);
					}
					if (fallenFigure[i].isEmptyFigure()) {
						fallenFigure.erase(fallenFigure.begin() + i);
						i--;
						size--;
					}
				}
			}
			bool isFigureMoveDown = true;
			while (isFigureMoveDown) {
				isFigureMoveDown = false;
				for (auto& figure : fallenFigure) {
					if (moveFigureBottom(figure)) {
						isFigureMoveDown = true;
					}
				}
			}
			lineIndex = field.clearLine();
		}
	}
	window.setStateField(field);
}

void Game::show()
{
	window.show();
	//field.printField();
	//std::cout << std::endl;
}

void Game::restart()
{
	field = PlayingField();
	currentFigure = generator.getNewFigure();
	nextFigure = generator.getNewFigure();
	fallenFigure = std::vector<Figure>();
	score = 0;
	field.addNewFigureToTheField(currentFigure.getVectorCoordinates(), currentFigure.getColor());
	isCanMoveDownCurrentFigure = true;
	isGameOver = false;
	window.setScore(score);
	window.setStateField(field);
	window.setNextFigure(nextFigure);
	window.setGameOver(false);
	timer.restart();
}

void Game::moveFigureRight()
{
	if (!isCanMoveDownCurrentFigure) {
		return;
	}

	std::vector<Coordinates> currentCoordinates = currentFigure.getVectorCoordinates();
	currentFigure.moveRight();
	std::vector<Coordinates> newCoordinates = currentFigure.getVectorCoordinates();
	bool isMoveRight = field.updateFigureCoordinates(currentCoordinates, newCoordinates);
	if (!isMoveRight) {
		currentFigure.moveLeft();
	}
}

void Game::moveFigureLeft()
{
	if (!isCanMoveDownCurrentFigure) {
		return;
	}

	std::vector<Coordinates> currentCoordinates = currentFigure.getVectorCoordinates();
	currentFigure.moveLeft();
	std::vector<Coordinates> newCoordinates = currentFigure.getVectorCoordinates();
	bool isMoveLeft = field.updateFigureCoordinates(currentCoordinates, newCoordinates);
	if (!isMoveLeft) {
		currentFigure.moveRight();
	}
}

bool Game::moveFigureDown()
{
	std::vector<Coordinates> currentCoordinates = currentFigure.getVectorCoordinates();
	currentFigure.moveDown();
	std::vector<Coordinates> newCoordinates = currentFigure.getVectorCoordinates();
	bool isMoveDown = field.updateFigureCoordinates(currentCoordinates, newCoordinates);
	if (!isMoveDown) {
		currentFigure.moveUp();
	}
	return isMoveDown;
}

void Game::moveFigureBottom()
{
	bool isCanMoveDown = moveFigureDown();
	while (isCanMoveDown) {
		isCanMoveDown = moveFigureDown();
	}
}

void Game::rotateFigure()
{
	if (!isCanMoveDownCurrentFigure) {
		return;
	}

	std::vector<Coordinates> currentCoordinates = currentFigure.getVectorCoordinates();
	currentFigure.rotate();
	std::vector<Coordinates> newCoordinates = currentFigure.getVectorCoordinates();
	bool isRotate = field.updateFigureCoordinates(currentCoordinates, newCoordinates);
	if (!isRotate) {
		currentFigure.rotate();
		currentFigure.rotate();
		currentFigure.rotate();
	}
}

bool Game::GameOver()
{
	return isGameOver;
}

bool Game::isOpenWindow()
{
	return window.isOpen();
}
