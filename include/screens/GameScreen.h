#pragma once
#include <iostream>
#include "libraries/Screen/Screen.h"
#include "libraries/Screen/ScreenStore.h"
#include "libraries/Screen/ScreenManager.h"
#include "libraries/Game/GameController.h"
#include "libraries/Menu/Menu.h"

class GameScreen : public Screen
{
private:
  ScreenStore *game_screen_store;
  ScreenManager *game_screen_manager;
  GameController *game;
  std::function<void()> fn_exit;

public:
  GameScreen();
  void Initialize();
  void Terminate();
  void Run();
};
