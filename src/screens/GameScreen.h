#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "Game/GameController.h"
#include "Screen/Screen.h"
#include "Menu/Menu.h"

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

#endif