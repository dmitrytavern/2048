#pragma once
#include <iostream>
#include "libraries/Game/GameController.h"
#include "libraries/Screen/Screen.h"
#include "libraries/Menu/Menu.h"

class GameOverScreen : public Screen
{
private:
  Menu *screen_menu;
  GameController **game;
  std::function<void()> fn_exit;
  std::function<void()> fn_call_game_play;

public:
  GameOverScreen(GameController **game);
  void Initialize();
  void Terminate();
  void Render();
  void Run();
};
