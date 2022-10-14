#pragma once
#include "libraries/Screen/Screen.h"
#include "libraries/Menu/Menu.h"

class MainScreen : public Screen
{
  using Screen::Screen;

private:
  Menu *screen_menu;
  function<void()> fn_exit;
  function<void()> fn_start_game;

public:
  void Initialize();
  void Terminate();
  void Graphics();
  void Run();
};
