#include "global.h"
#include "libraries/Screen/ScreenSignal.h"
#include "libraries/Menu/Menu.h"
#include "libraries/Menu/MenuUI.h"
#include "libraries/UI/UI.h"
#include "screens/MainScreen.h"

enum Triggers
{
  MAIN_MENU_START_GAME_KEY = 97,
  MAIN_MENU_CLOSE_GAME_KEY = 101,
};

MainScreen::MainScreen() : Screen(SCREEN_MAIN_NAME)
{
  this->fn_exit = [&]() -> void
  {
    this->SetSignal(SCREEN_SIGNAL_EXIT);
  };

  this->fn_start_game = [&]() -> void
  {
    this->SetSignal(SCREEN_SIGNAL_SET, SCREEN_GAME_NAME);
  };
}

void MainScreen::Initialize()
{
  Menu *screen_menu = new Menu;
  screen_menu->SetTitle("Main");
  screen_menu->AddAction(MAIN_MENU_START_GAME_KEY, "a - start game", this->fn_start_game);
  screen_menu->AddAction(MAIN_MENU_CLOSE_GAME_KEY, "e - close game", this->fn_exit);
  this->screen_menu = screen_menu;
}

void MainScreen::Terminate()
{
  delete (this->screen_menu);
}

void MainScreen::Render()
{
  UI::PrintVerticalAlign(6);
  UI::PrintCenter("━━━━ 2048 Game Menu ━━━━", 24);
  UI::Print();

  MenuUI::PrintMenu(this->screen_menu->GetTitle(), this->screen_menu->GetActionNames());
}

void MainScreen::Run()
{
  Menu::ActivateMenu(this->screen_menu);
}
