#pragma once
#include <iostream>
#include "libraries/Screen/Screen.h"
#include "libraries/Menu/Menu.h"

class MainScreen : public Screen
{
private:
  Menu *screen_menu;
  std::function<void()> fn_exit;
  std::function<void()> fn_start_game;

public:
  MainScreen();
  void Initialize();
  void Terminate();
  void Render();
  void Run();
};
