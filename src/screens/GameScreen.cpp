#include <iostream>
#include <functional>
#include "Menu/Menu.h"
#include "Menu/MenuUI.h"
#include "Game/GameUI.h"
#include "UI/UI.h"

#include "GameScreen.h"

#define SCREEN_NAME "game"

enum Triggers
{
  GAME_MENU_SWIPE_UP_KEY = 119,
  GAME_MENU_SWIPE_LEFT_KEY = 97,
  GAME_MENU_SWIPE_DOWN_KEY = 115,
  GAME_MENU_SWIPE_RIGHT_KEY = 100,
  GAME_MENU_EXIT_KEY = 101,
  GAME_MENU_START_GAME_KEY = 97,
};

string GameScreen::GetName()
{
  return SCREEN_NAME;
}

void GameScreen::Initialize()
{
  this->fn_exit_to_main_screen = [&]() -> void
  {
    this->app_screen_manager->Set("main");
  };

  this->fn_exit = [&]() -> void
  {
    this->app_screen_manager->Exit();
  };

  this->fn_start_game = [&]() -> void
  {
    this->CallInitializeGame();
  };

  this->fn_start_game();
}

void GameScreen::Graphic()
{
  GameMatrix *matrix = this->game->GetMatrix();

  UI::PrintVerticalAlign(4 * 3 + 2 + 1 + 7);
  UI::PrintCenter("━━━━ 2048 Game Session ━━━━", 28);

  GameUI::OutputMatrix(matrix);

  MenuUI::PrintMenu(this->screen_menu);
}

void GameScreen::Action()
{
  MenuUI::ActivateMenu(this->screen_menu);

  if (!this->game->ExistsMove())
    this->CallGameOver();
}

void GameScreen::CallInitializeGame()
{
  this->game = new GameController();

  Menu *screen_menu = new Menu;
  screen_menu->SetTitle("Control");
  screen_menu->AddAction(GAME_MENU_SWIPE_UP_KEY, "w - swipe to up", std::bind(&GameController::SwipeUp, this->game));
  screen_menu->AddAction(GAME_MENU_SWIPE_LEFT_KEY, "a - swipe to left", std::bind(&GameController::SwipeLeft, this->game));
  screen_menu->AddAction(GAME_MENU_SWIPE_DOWN_KEY, "s - swipe to down", std::bind(&GameController::SwipeDown, this->game));
  screen_menu->AddAction(GAME_MENU_SWIPE_RIGHT_KEY, "d - swipe to right", std::bind(&GameController::SwipeRight, this->game));
  screen_menu->AddAction(GAME_MENU_EXIT_KEY, "e - exit", this->fn_exit_to_main_screen);
  this->screen_menu = screen_menu;

  this->game->Start();
}

void GameScreen::CallGameOver()
{
  Menu *screen_menu = new Menu;
  screen_menu->SetTitle("Game Over");
  screen_menu->AddAction(GAME_MENU_START_GAME_KEY, "a - new game", this->fn_start_game);
  screen_menu->AddAction(GAME_MENU_EXIT_KEY, "e - close game", this->fn_exit);
  this->screen_menu = screen_menu;
}

void GameScreen::Exit()
{
  delete (this->screen_menu);
  delete (this->game);
}
