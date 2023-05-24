#pragma once
#include "../libraries/Screen/Screen.h"
#include "../libraries/Screen/ScreenManager.h"
#include "../libraries/Screen/ScreenStore.h"
#include <iostream>

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
