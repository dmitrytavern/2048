#include <string>
#include "global.h"
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

GamePlayScreen::GamePlayScreen(GameController **game) : Screen(SCREEN_GAME_PLAY_NAME)
{
  this->fn_exit = [&]() -> void
  {
    this->SetSignal(SCREEN_SIGNAL_EXIT);
  };

  this->fn_call_game_over = [&]() -> void
  {
    this->SetSignal(SCREEN_SIGNAL_SET, SCREEN_GAME_OVER_NAME);
  };

  this->game = game;
}

void GamePlayScreen::Initialize()
{
  (*this->game)->Start();

  Menu *screen_menu = new Menu;
  screen_menu->SetTitle("Control");
  screen_menu->AddAction(GAME_MENU_SWIPE_UP_KEY, "w - swipe to up", std::bind(&GameController::SwipeUp, (*this->game)));
  screen_menu->AddAction(GAME_MENU_SWIPE_LEFT_KEY, "a - swipe to left", std::bind(&GameController::SwipeLeft, (*this->game)));
  screen_menu->AddAction(GAME_MENU_SWIPE_DOWN_KEY, "s - swipe to down", std::bind(&GameController::SwipeDown, (*this->game)));
  screen_menu->AddAction(GAME_MENU_SWIPE_RIGHT_KEY, "d - swipe to right", std::bind(&GameController::SwipeRight, (*this->game)));
  screen_menu->AddAction(GAME_MENU_EXIT_KEY, "e - exit", this->fn_exit);
  this->screen_menu = screen_menu;
}

void GamePlayScreen::Terminate()
{
  delete (this->screen_menu);
}

void GamePlayScreen::Render()
{
  GameMatrix *matrix = (*this->game)->GetMatrix();
  int score = (*this->game)->GetScore();

  UI::PrintVerticalAlign(4 * 3 + 2 + 1 + 7);
  UI::PrintCenter("━━━━ 2048 Game Session ━━━━", 28);
  UI::PrintCenter("Your score: " + std::to_string(score));

  GameUI::OutputMatrix(matrix->GetMatrix(), matrix->GetMatrixSize());

  MenuUI::PrintMenu(this->screen_menu);
}

void GamePlayScreen::Run()
{
  MenuUI::ActivateMenu(this->screen_menu);

  if (!(*this->game)->ExistsMove())
    this->fn_call_game_over();
}
