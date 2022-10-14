#include "ScreenNames.h"

#include "libraries/Screen/ScreenSignal.h"
#include "libraries/Menu/Menu.h"
#include "libraries/Menu/MenuUI.h"
#include "libraries/Game/GameUI.h"
#include "libraries/UI/UI.h"

#include "screens/GameScreen.h"

enum Triggers
{
  GAME_MENU_SWIPE_UP_KEY = 119,
  GAME_MENU_SWIPE_LEFT_KEY = 97,
  GAME_MENU_SWIPE_DOWN_KEY = 115,
  GAME_MENU_SWIPE_RIGHT_KEY = 100,
  GAME_MENU_EXIT_KEY = 101,
  GAME_MENU_START_GAME_KEY = 97,
};

GameScreen::GameScreen() : Screen(SCREEN_GAME_NAME)
{
  this->fn_exit = [&]() -> void
  {
    this->SetSignal(SCREEN_SIGNAL_EXIT);
  };

  this->fn_exit_to_main_screen = [&]() -> void
  {
    this->SetSignal(SCREEN_SIGNAL_SET, SCREEN_MAIN_NAME);
  };
}

void GameScreen::Initialize()
{
  this->CallStartGame();
}

void GameScreen::Terminate()
{
  delete (this->screen_menu);
  delete (this->game);
}

void GameScreen::Render()
{
  GameMatrix *matrix = this->game->GetMatrix();

  UI::PrintVerticalAlign(4 * 3 + 2 + 1 + 7);
  UI::PrintCenter("━━━━ 2048 Game Session ━━━━", 28);

  GameUI::OutputMatrix(matrix);

  MenuUI::PrintMenu(this->screen_menu);
}

void GameScreen::Run()
{
  MenuUI::ActivateMenu(this->screen_menu);

  if (!this->game->ExistsMove())
    this->CallEndGame();
}

/**
 * GameScreen.CallStartGame()
 * -------------------------------------
 * Initialize new classes for the game.
 * Use it for start new game.
 */
void GameScreen::CallStartGame()
{
  this->game = new GameController();
  this->game->Start();

  Menu *screen_menu = new Menu;
  screen_menu->SetTitle("Control");
  screen_menu->AddAction(GAME_MENU_SWIPE_UP_KEY, "w - swipe to up", std::bind(&GameController::SwipeUp, this->game));
  screen_menu->AddAction(GAME_MENU_SWIPE_LEFT_KEY, "a - swipe to left", std::bind(&GameController::SwipeLeft, this->game));
  screen_menu->AddAction(GAME_MENU_SWIPE_DOWN_KEY, "s - swipe to down", std::bind(&GameController::SwipeDown, this->game));
  screen_menu->AddAction(GAME_MENU_SWIPE_RIGHT_KEY, "d - swipe to right", std::bind(&GameController::SwipeRight, this->game));
  screen_menu->AddAction(GAME_MENU_EXIT_KEY, "e - exit", this->fn_exit_to_main_screen);
  this->screen_menu = screen_menu;
}

/**
 * GameScreen.CallEndGame()
 * -------------------------------------
 * Initialize new classes for game over.
 * Use it for block the game control and
 * output result
 */
void GameScreen::CallEndGame()
{
  function<void()> fn_restart = [&]() -> void
  {
    this->CallStartGame();
  };

  Menu *screen_menu = new Menu;
  screen_menu->SetTitle("Game Over");
  screen_menu->AddAction(GAME_MENU_START_GAME_KEY, "a - new game", fn_restart);
  screen_menu->AddAction(GAME_MENU_EXIT_KEY, "e - close game", this->fn_exit);
  this->screen_menu = screen_menu;
}
