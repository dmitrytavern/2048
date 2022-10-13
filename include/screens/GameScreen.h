#pragma once
#include "../libraries/Game/GameController.h"
#include "../libraries/Screen/Screen.h"
#include "../libraries/Menu/Menu.h"

class GameScreen : public Screen
{
  using Screen::Screen;

private:
  Menu *screen_menu;
  GameController *game;
  function<void()> fn_exit;
  function<void()> fn_start_game;
  function<void()> fn_exit_to_main_screen;

  void CallInitializeGame();
  void CallGameOver();

public:
  string GetName();
  void Initialize();
  void Graphic();
  void Action();
  void Exit();
};
