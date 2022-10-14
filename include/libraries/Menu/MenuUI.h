#pragma once
#include <iostream>
#include "Menu.h"

using namespace std;

class MenuUI
{
public:
  static int BORDER_SIZE;
  static int BORDER_WINDOW_PADDING;

  static void PrintMenu(Menu *menu);
  static int ActivateMenu(Menu *menu);
  static int CalcContentSize(Menu *menu);
  static int CalcWindowsSize(int content_size);
};
