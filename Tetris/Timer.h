#pragma once

#include <SFML/System.hpp>

class Timer
{
private:
	sf::Clock clock;

public:
	Timer();

	float getCurrentTime();

	void restart();
};

