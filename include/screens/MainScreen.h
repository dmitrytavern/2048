#pragma once
#include <iostream>
#include "libraries/Screen/Screen.h"
#include "libraries/Menu/Menu.h"

class MainScreen : public Screen
{
private:
  Menu *screen_menu;

public:
  MainScreen();
  void Render();
  void Run();
};
