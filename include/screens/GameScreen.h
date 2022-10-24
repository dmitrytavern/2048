#pragma once
#include <iostream>
#include "libraries/Screen/Screen.h"
#include "libraries/Screen/ScreenStore.h"
#include "libraries/Screen/ScreenManager.h"

class GameScreen : public Screen
{
private:
  using Screen::Screen;
  ScreenStore *game_screen_store;
  ScreenManager *game_screen_manager;

public:
  void Initialize();
  void Terminate();
  void Run();
};
