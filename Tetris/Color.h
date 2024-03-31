#pragma once

#include <vector>

#define MAX_VALUE_COLOR 255

class Color
{
private:
	size_t red;
	size_t green;
	size_t blue;

public:
	Color();

	Color(size_t r, size_t g, size_t b);

	std::vector<size_t> getColor();
};

