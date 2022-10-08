#include <iostream>
#include "main.h"
#include "menus.h"

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

void InitMainMenu();
void InitGameMenu();
void InitGameOverMenu();
void Exit();

void InitMainMenu()
{
  ui_menu_main = new Menu;
  ui_menu_main->AddAction(MAIN_MENU_START_GAME_KEY, "a - start game", &InitGame);
  ui_menu_main->AddAction(MAIN_MENU_CLOSE_GAME_KEY, "e - close game", &Exit);
}

void InitGameMenu()
{
  std::function<void()> ActionSwipeUp = [&]() -> void
  {
    controller->SwipeUp();
    controller->FillRandomCell();
    if (matrix->GetEmptyCellCount() == 0)
      ui_screen->SetScreen("game_over");
  };

  std::function<void()> ActionSwipeLeft = [&]() -> void
  {
    controller->SwipeLeft();
    controller->FillRandomCell();
    if (matrix->GetEmptyCellCount() == 0)
      ui_screen->SetScreen("game_over");
  };

  std::function<void()> ActionSwipeDown = [&]() -> void
  {
    controller->SwipeDown();
    controller->FillRandomCell();
    if (matrix->GetEmptyCellCount() == 0)
      ui_screen->SetScreen("game_over");
  };

  std::function<void()> ActionSwipeRight = [&]() -> void
  {
    controller->SwipeRight();
    controller->FillRandomCell();
    if (matrix->GetEmptyCellCount() == 0)
      ui_screen->SetScreen("game_over");
  };

  std::function<void()> ActionSetMenu = [&]() -> void
  {
    ui_screen->SetScreen("main");
  };

  ui_menu_game = new Menu;
  ui_menu_game->AddAction(GAME_MENU_SWIPE_UP_KEY, "w - swipe to up", ActionSwipeUp);
  ui_menu_game->AddAction(GAME_MENU_SWIPE_LEFT_KEY, "a - swipe to left", ActionSwipeLeft);
  ui_menu_game->AddAction(GAME_MENU_SWIPE_DOWN_KEY, "s - swipe to down", ActionSwipeDown);
  ui_menu_game->AddAction(GAME_MENU_SWIPE_RIGHT_KEY, "d - swipe to right", ActionSwipeRight);
  ui_menu_game->AddAction(GAME_MENU_EXIT_KEY, "e - exit", ActionSetMenu);
}

void InitGameOverMenu()
{
  ui_menu_game_over = new Menu;
  ui_menu_game_over->AddAction(GAME_OVER_MENU_START_GAME_KEY, "a - new game", &InitGame);
  ui_menu_game_over->AddAction(GAME_OVER_MENU_EXIT_KEY, "e - close game", &Exit);
}

void Exit()
{
  exit(0);
}
