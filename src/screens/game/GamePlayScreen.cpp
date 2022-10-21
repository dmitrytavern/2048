#include <string>
#include "global.h"
#include "core/Core.h"
#include "core/CoreMatrix.h"
#include "core/CoreScore.h"
#include "libraries/UI/UI.h"
#include "libraries/Menu/Menu.h"
#include "libraries/Menu/MenuUI.h"
#include "libraries/Game/GameUI.h"
#include "screens/game/GamePlayScreen.h"

enum Triggers
{
  GAME_MENU_SWIPE_UP_KEY = 119,
  GAME_MENU_SWIPE_LEFT_KEY = 97,
  GAME_MENU_SWIPE_DOWN_KEY = 115,
  GAME_MENU_SWIPE_RIGHT_KEY = 100,
  GAME_MENU_EXIT_KEY = 101,
};

GamePlayScreen::GamePlayScreen() : Screen(SCREEN_GAME_PLAY_NAME)
{
  this->fn_exit = [&]() -> void
  {
    this->SetSignal(SCREEN_SIGNAL_EXIT);
  };

  this->fn_call_game_over = [&]() -> void
  {
    this->SetSignal(SCREEN_SIGNAL_SET, SCREEN_GAME_OVER_NAME);
  };
}

void GamePlayScreen::Initialize()
{
  Core::ToStartGame();

  Menu *screen_menu = new Menu;
  screen_menu->SetTitle("Control");
  screen_menu->AddAction(GAME_MENU_SWIPE_UP_KEY, "w - swipe to up", std::bind(Core::ToMove, Core::Matrix::SWIPE_DIRECTION_UP));
  screen_menu->AddAction(GAME_MENU_SWIPE_LEFT_KEY, "a - swipe to left", std::bind(Core::ToMove, Core::Matrix::SWIPE_DIRECTION_LEFT));
  screen_menu->AddAction(GAME_MENU_SWIPE_DOWN_KEY, "s - swipe to down", std::bind(Core::ToMove, Core::Matrix::SWIPE_DIRECTION_DOWN));
  screen_menu->AddAction(GAME_MENU_SWIPE_RIGHT_KEY, "d - swipe to right", std::bind(Core::ToMove, Core::Matrix::SWIPE_DIRECTION_RIGHT));
  screen_menu->AddAction(GAME_MENU_EXIT_KEY, "e - exit", this->fn_exit);
  this->screen_menu = screen_menu;
}

void GamePlayScreen::Terminate()
{
  delete (this->screen_menu);
}

void GamePlayScreen::Render()
{
  UI::PrintVerticalAlign(4 * 3 + 2 + 1 + 7);
  UI::PrintCenter("━━━━ 2048 Game Session ━━━━", 28);
  UI::PrintCenter("Your score: " + std::to_string(Core::Score::Get()));

  GameUI::OutputMatrix(Core::Matrix::Get(), Core::Matrix::GetSize());

  MenuUI::PrintMenu(this->screen_menu->GetTitle(), this->screen_menu->GetActionNames());
}

void GamePlayScreen::Run()
{
  Menu::ActivateMenu(this->screen_menu);

  if (!Core::ExistsMove())
    this->fn_call_game_over();
}
