#pragma once
#include <iostream>
#include "libraries/Screen/Screen.h"
#include "libraries/Menu/Menu.h"

class GamePlayScreen : public Screen
{
private:
  Menu *screen_menu;
  std::function<void()> fn_exit;
  std::function<void()> fn_call_game_over;

public:
  GamePlayScreen();
  void Initialize();
  void Terminate();
  void Render();
  void Run();
};
