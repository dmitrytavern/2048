#pragma once
#include "../libraries/Menu/Menu.h"
#include "../libraries/Screen/Screen.h"
#include <iostream>

class MainScreen : public Screen
{
private:
  Menu *screen_menu;

public:
  MainScreen();
  ~MainScreen();
  void Render();
  void Run();
};
