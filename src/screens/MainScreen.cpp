#include <vector>
#include "global.h"
#include "interface/Interface.h"
#include "interface/MenuInterface.h"
#include "interface/WindowInterface.h"
#include "interface/TerminalInterface.h"
#include "interface/DialogInterface.h"
#include "screens/MainScreen.h"

enum Triggers
{
  MAIN_MENU_START_GAME_CODE = 1,
  MAIN_MENU_CLOSE_GAME_CODE = 2,
  MAIN_MENU_ABOUT_GAME_CODE = 3,
};

MainScreen::MainScreen() : Screen(SCREEN_MAIN_NAME)
{
  this->screen_menu = new Menu;
  this->screen_menu->AddElement(MAIN_MENU_START_GAME_CODE, "Start game");
  this->screen_menu->AddElement(MAIN_MENU_ABOUT_GAME_CODE, "About me");
  this->screen_menu->AddElement(MAIN_MENU_CLOSE_GAME_CODE, "Exit");
}

void MainScreen::Render()
{
  if (Interface::Terminal::GetWidth() >= 58)
  {
    Interface::Window::OutputCenter("$$$$$$$\\            $$\\      $$\\           $$$$$$$\\  ");
    Interface::Window::OutputCenter("$$  __$$\\           $$ | $\\  $$ |          $$  __$$\\ ");
    Interface::Window::OutputCenter("$$ |  $$ | $$$$$$\\  $$ |$$$\\ $$ | $$$$$$\\  $$ |  $$ |");
    Interface::Window::OutputCenter("$$$$$$$  |$$  __$$\\ $$ $$ $$\\$$ |$$  __$$\\ $$$$$$$  |");
    Interface::Window::OutputCenter("$$  ____/ $$ /  $$ |$$$$  _$$$$ |$$$$$$$$ |$$  __$$< ");
    Interface::Window::OutputCenter("$$ |      $$ |  $$ |$$$  / \\$$$ |$$   ____|$$ |  $$ |");
    Interface::Window::OutputCenter("$$ |      \\$$$$$$  |$$  /   \\$$ |\\$$$$$$$\\ $$ |  $$ |");
    Interface::Window::OutputCenter("\\__|       \\______/ \\__/     \\__| \\_______|\\__|  \\__|");
  }
  else
  {
    Interface::Window::OutputCenter("Power");
  }

  Interface::Output("\n\n");

  Interface::Menu::Output(this->screen_menu);

  Interface::Window::AlignVertically();
  Interface::Terminal::Clear();
  Interface::Print();
}

void MainScreen::Run()
{
  const int code = Interface::Menu::Activate(this->screen_menu);

  switch (code)
  {
  case MAIN_MENU_START_GAME_CODE:
    this->SetSignal(SCREEN_SIGNAL_SET, SCREEN_GAME_NAME);
    break;

  case MAIN_MENU_ABOUT_GAME_CODE:
    this->SetSignal(SCREEN_SIGNAL_SET, SCREEN_ABOUT_NAME);
    break;

  case MAIN_MENU_CLOSE_GAME_CODE:
    this->SetSignal(SCREEN_SIGNAL_SET, SCREEN_EXIT_NAME);
    break;
  }
}
