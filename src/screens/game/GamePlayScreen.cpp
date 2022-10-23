#include <string>
#include "global.h"
#include "core/Core.h"
#include "core/CoreMatrix.h"
#include "core/CoreScore.h"
#include "interface/Interface.h"
#include "interface/MenuInterface.h"
#include "interface/WindowInterface.h"
#include "interface/MatrixInterface.h"
#include "interface/DialogInterface.h"
#include "libraries/Menu/Menu.h"
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
  unsigned int matrix_size = Core::Matrix::GetSize();
  unsigned int matrix_cell_height = Interface::Matrix::CELL_HEIGHT;
  unsigned int matrix_borders = Interface::Matrix::BORDER_SIZE * 2;
  unsigned int menu_borders = Interface::Menu::BORDER_SIZE * 2;
  unsigned int matrix_print_rows = matrix_size * matrix_cell_height + matrix_borders;
  unsigned int menu_print_rows = menu_borders + this->screen_menu->GetActionsLength();
  unsigned int other_print_rows = 2; // Score, Title

  Interface::Window::PrintVerticalAlign(matrix_print_rows + menu_print_rows + other_print_rows);

#ifdef __linux__
  Interface::Window::PrintCenter("━━━━ 2048 Game Session ━━━━", 28);
#else
  Interface::Window::PrintCenter("---- 2048 Game Session ----");
#endif

  Interface::Window::PrintCenter("Your score: " + std::to_string(Core::Score::Get()));

  Interface::Matrix::Print(Core::Matrix::Get(), Core::Matrix::GetSize());

  Interface::Menu::Print(this->screen_menu->GetTitle(), this->screen_menu->GetActionNames());
}

void GamePlayScreen::Run()
{
  const int code = Interface::Dialog::GetCharCode();

  this->screen_menu->Trigger(code);

  if (!Core::ExistsMove())
    this->fn_call_game_over();
}
