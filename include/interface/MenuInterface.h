#pragma once
#include <string>
#include <vector>
#include "libraries/Menu/Menu.h"

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

  void Print(_Menu *menu);

  int Activate(_Menu *menu);
}