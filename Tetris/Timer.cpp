#include "Timer.h"

Timer::Timer()
{
	clock.restart();
}

float Timer::getCurrentTime()
{
	return clock.getElapsedTime().asMilliseconds();
}

void Timer::restart()
{
	clock.restart();
}
