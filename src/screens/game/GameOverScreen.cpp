#include <iostream>
#include <string>
#include "global.h"
#include "core/Core.h"
#include "core/CoreMatrix.h"
#include "core/CoreScore.h"
#include "interface/Interface.h"
#include "interface/MenuInterface.h"
#include "interface/WindowInterface.h"
#include "interface/MatrixInterface.h"
#include "libraries/Menu/Menu.h"
#include "screens/game/GameOverScreen.h"

enum Triggers
{
  GAME_MENU_START_GAME_KEY = 97,
  GAME_MENU_EXIT_KEY = 101,
};

GameOverScreen::GameOverScreen() : Screen(SCREEN_GAME_OVER_NAME)
{
  this->fn_exit = [&]() -> void
  {
    this->SetSignal(SCREEN_SIGNAL_EXIT);
  };

  this->fn_call_game_play = [&]() -> void
  {
    this->SetSignal(SCREEN_SIGNAL_SET, SCREEN_GAME_PLAY_NAME);
  };
}

void GameOverScreen::Initialize()
{
  Menu *screen_menu = new Menu;
  screen_menu->SetTitle("Game Over");
  screen_menu->AddAction(GAME_MENU_START_GAME_KEY, "a - new game", this->fn_call_game_play);
  screen_menu->AddAction(GAME_MENU_EXIT_KEY, "e - close game", this->fn_exit);
  this->screen_menu = screen_menu;
}

void GameOverScreen::Terminate()
{
  delete (this->screen_menu);
}

void GameOverScreen::Render()
{
  Interface::Window::PrintVerticalAlign(4 * 3 + 2 + 1 + 7);
#ifdef __linux__
  Interface::Window::PrintCenter("━━━━ 2048 Game Session ━━━━", 24);
#else
  Interface::Window::PrintCenter("---- 2048 Game Session ----");
#endif
  Interface::Window::PrintCenter("Your result: " + std::to_string(Core::Score::Get()));

  Interface::Matrix::Print(Core::Matrix::Get(), Core::Matrix::GetSize());

  Interface::Menu::Print(this->screen_menu->GetTitle(), this->screen_menu->GetActionNames());
}

void GameOverScreen::Run()
{
  Menu::ActivateMenu(this->screen_menu);
}
