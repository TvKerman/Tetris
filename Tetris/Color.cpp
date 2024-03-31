#include "Color.h"

Color::Color()
{
	red = MAX_VALUE_COLOR;
	green = MAX_VALUE_COLOR;
	blue = MAX_VALUE_COLOR;
}

Color::Color(size_t r, size_t g, size_t b)
{
	if (r > MAX_VALUE_COLOR) {
		r = MAX_VALUE_COLOR;
	}
	if (g > MAX_VALUE_COLOR) {
		g = MAX_VALUE_COLOR;
	}
	if (b > MAX_VALUE_COLOR) {
		b = MAX_VALUE_COLOR;
	}
	red = r;
	green = g;
	blue = b;
}

std::vector<size_t> Color::getColor()
{
	return {red, green, blue};
}
