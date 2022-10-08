#include <iostream>
#include <functional>
#include "main.h"
#include "menus.h"

using namespace std;

enum Triggers
{
  MAIN_MENU_START_GAME_KEY = 97,
  MAIN_MENU_CLOSE_GAME_KEY = 101,

  GAME_MENU_SWIPE_UP_KEY = 119,
  GAME_MENU_SWIPE_LEFT_KEY = 97,
  GAME_MENU_SWIPE_DOWN_KEY = 115,
  GAME_MENU_SWIPE_RIGHT_KEY = 100,
  GAME_MENU_EXIT_KEY = 101,

  GAME_OVER_MENU_START_GAME_KEY = 97,
  GAME_OVER_MENU_EXIT_KEY = 101,
};

void InitGame()
{
  game.Start();

  ui_game->SetMatrix(*game.GetMatrix());
  ui_screen->SetScreen("game");
}

void InitMainMenu()
{
  Menu main_menu;
  main_menu.SetName("main");
  main_menu.AddAction(MAIN_MENU_START_GAME_KEY, "a - start game", &InitGame);
  main_menu.AddAction(MAIN_MENU_CLOSE_GAME_KEY, "e - close game", &Exit);
  ui_menu->AddMenu(main_menu);
}

void InitGameMenu()
{
  std::function<void()> ExitFromGame = [&]() -> void
  {
    ui_screen->SetScreen("main");
  };

  Menu game_menu;
  game_menu.SetName("game");
  game_menu.AddAction(GAME_MENU_SWIPE_UP_KEY, "w - swipe to up", std::bind(&GameController::SwipeUp, &game));
  game_menu.AddAction(GAME_MENU_SWIPE_LEFT_KEY, "a - swipe to left", std::bind(&GameController::SwipeLeft, &game));
  game_menu.AddAction(GAME_MENU_SWIPE_DOWN_KEY, "s - swipe to down", std::bind(&GameController::SwipeDown, &game));
  game_menu.AddAction(GAME_MENU_SWIPE_RIGHT_KEY, "d - swipe to right", std::bind(&GameController::SwipeRight, &game));
  game_menu.AddAction(GAME_MENU_EXIT_KEY, "e - exit", ExitFromGame);
  ui_menu->AddMenu(game_menu);
}

void InitGameOverMenu()
{
  Menu game_over_menu;
  game_over_menu.SetName("game_over");
  game_over_menu.AddAction(GAME_OVER_MENU_START_GAME_KEY, "a - new game", &InitGame);
  game_over_menu.AddAction(GAME_OVER_MENU_EXIT_KEY, "e - close game", &Exit);
  ui_menu->AddMenu(game_over_menu);
}

void Exit()
{
  ui_screen->Exit();
}
