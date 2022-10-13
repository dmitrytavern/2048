#include "Screen/ScreenManager.h"
#include "Menu/Menu.h"
#include "Menu/MenuUI.h"
#include "UI/UI.h"

#include "MainScreen.h"

#define MAIN_NAME "main"

enum Triggers
{
  MAIN_MENU_START_GAME_KEY = 97,
  MAIN_MENU_CLOSE_GAME_KEY = 101,
};

string MainScreen::GetName()
{
  return MAIN_NAME;
}

void MainScreen::Initialize()
{
  function<void()> StartGame = [&]() -> void
  {
    Screen *game_screen = this->app_screen_store->GetScreen("game");
    this->app_screen_manager->Set(game_screen);
  };

  function<void()> Exit = [&]() -> void
  {
    this->app_screen_manager->Exit();
  };

  Menu *screen_menu = new Menu;
  screen_menu->SetTitle("Main");
  screen_menu->AddAction(MAIN_MENU_START_GAME_KEY, "a - start game", StartGame);
  screen_menu->AddAction(MAIN_MENU_CLOSE_GAME_KEY, "e - close game", Exit);
  this->screen_menu = screen_menu;
}

void MainScreen::Graphic()
{
  UI::PrintVerticalAlign(6);
  UI::PrintCenter("━━━━ 2048 Game Menu ━━━━", 24);
  UI::Print("");

  MenuUI::PrintMenu(this->screen_menu);
}

void MainScreen::Action()
{
  MenuUI::ActivateMenu(this->screen_menu);
}

void MainScreen::Exit()
{
  delete (this->screen_menu);
}
