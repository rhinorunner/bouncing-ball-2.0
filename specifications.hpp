#pragma once

#include <iostream>

namespace ball
{
	/** PROGRAM SPECIFICATIONS **/

	// screen width
	static constexpr uint32_t SCREENWIDTH = 500;
	// screen height
	static constexpr uint32_t SCREENHEIGHT = 500;

	// ball trail length
	static constexpr uint32_t TRAIL_LENGTH = 0;
}

/** USEFUL CODE **/

static bool QUIT = false;
	
static constexpr double PI = 3.1415926535929;

#define loop(x) for (uint32_t i = 0; i < x; ++i)

struct RGBA_t {
	uint8_t R;
	uint8_t G;
	uint8_t B;
	uint8_t A;
};