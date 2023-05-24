#pragma once
#include "../libraries/Menu/Menu.h"
#include <string>
#include <vector>

using _Menu = Menu;

namespace Interface::Menu
{
#ifdef __linux__
const int ELEMENT_COLOR = 250;
const int ACTIVE_ELEMENT_COLOR = 255;
#else
const int ELEMENT_COLOR = 90;
const int ACTIVE_ELEMENT_COLOR = 97;
#endif

void Output(_Menu *menu);

int Activate(_Menu *menu);
} // namespace Interface::Menu