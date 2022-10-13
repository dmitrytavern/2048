#pragma once
#include "libraries/Screen/Screen.h"
#include "libraries/Menu/Menu.h"

class MainScreen : public Screen
{
  using Screen::Screen;

private:
  Menu *screen_menu;

public:
  string GetName();
  void Initialize();
  void Graphic();
  void Action();
  void Exit();
};
