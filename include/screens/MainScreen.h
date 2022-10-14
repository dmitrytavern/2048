#pragma once
#include "libraries/Screen/Screen.h"
#include "libraries/Menu/Menu.h"

class MainScreen : public Screen
{
private:
  Menu *screen_menu;
  function<void()> fn_exit;
  function<void()> fn_start_game;

public:
  MainScreen();
  void Initialize();
  void Terminate();
  void Render();
  void Run();
};
