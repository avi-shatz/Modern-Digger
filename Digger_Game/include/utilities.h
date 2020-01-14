#pragma once
#include <random>

enum class Dir{ Non, Up, Down, Right, Left };

// getting a true random number between min - max
size_t random_generator(size_t min, size_t max);