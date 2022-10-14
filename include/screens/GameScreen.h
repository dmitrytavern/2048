#pragma once
#include "libraries/Game/GameController.h"
#include "libraries/Screen/Screen.h"
#include "libraries/Menu/Menu.h"

class GameScreen : public Screen
{
private:
  Menu *screen_menu;
  GameController *game;
  function<void()> fn_exit;
  function<void()> fn_exit_to_main_screen;

  void CallStartGame();
  void CallEndGame();

public:
  GameScreen();
  void Initialize();
  void Terminate();
  void Render();
  void Run();
};
