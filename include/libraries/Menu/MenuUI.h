#pragma once
#include <iostream>
#include "Menu.h"

class MenuUI
{
public:
  static const int BORDER_SIZE;
  static const int BORDER_WINDOW_PADDING;

  static void PrintMenu(Menu *menu);
  static int ActivateMenu(Menu *menu);
  static int CalcContentSize(Menu *menu);
  static int CalcWindowsSize(int content_size);
};
