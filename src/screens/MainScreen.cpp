#include <vector>
#include "global.h"
#include "interface/Interface.h"
#include "interface/MenuInterface.h"
#include "interface/BannerInterface.h"
#include "interface/WindowInterface.h"
#include "interface/TerminalInterface.h"
#include "interface/DialogInterface.h"
#include "screens/MainScreen.h"

enum Triggers
{
  MAIN_MENU_START_GAME_CODE = 1,
  MAIN_MENU_CLOSE_GAME_CODE = 2,
};

MainScreen::MainScreen() : Screen(SCREEN_MAIN_NAME)
{
  this->screen_menu = new Menu;
  this->screen_menu->AddElement(MAIN_MENU_START_GAME_CODE, "Start game");
  this->screen_menu->AddElement(MAIN_MENU_CLOSE_GAME_CODE, "Exit");
}

void MainScreen::Render()
{
  unsigned int menu_borders = Interface::Banner::BORDER_SIZE * 2 + 2;
  unsigned int other_print_rows = 10; // Title and \n

  Interface::Window::PrintVerticalAlign(menu_borders + other_print_rows);

  if (Interface::Terminal::GetTerminalWidth() >= 58)
  {
    Interface::Window::PrintCenter("$$$$$$$\\            $$\\      $$\\           $$$$$$$\\  ");
    Interface::Window::PrintCenter("$$  __$$\\           $$ | $\\  $$ |          $$  __$$\\ ");
    Interface::Window::PrintCenter("$$ |  $$ | $$$$$$\\  $$ |$$$\\ $$ | $$$$$$\\  $$ |  $$ |");
    Interface::Window::PrintCenter("$$$$$$$  |$$  __$$\\ $$ $$ $$\\$$ |$$  __$$\\ $$$$$$$  |");
    Interface::Window::PrintCenter("$$  ____/ $$ /  $$ |$$$$  _$$$$ |$$$$$$$$ |$$  __$$< ");
    Interface::Window::PrintCenter("$$ |      $$ |  $$ |$$$  / \\$$$ |$$   ____|$$ |  $$ |");
    Interface::Window::PrintCenter("$$ |      \\$$$$$$  |$$  /   \\$$ |\\$$$$$$$\\ $$ |  $$ |");
    Interface::Window::PrintCenter("\\__|       \\______/ \\__/     \\__| \\_______|\\__|  \\__|");
  }
  else
  {
    Interface::Window::PrintCenter("Power");
  }

  Interface::Print("\n\n");

  Interface::Menu::Print(this->screen_menu);
}

void MainScreen::Run()
{
  const int code = Interface::Menu::Activate(this->screen_menu);

  switch (code)
  {
  case MAIN_MENU_START_GAME_CODE:
    this->SetSignal(SCREEN_SIGNAL_SET, SCREEN_GAME_NAME);
    break;

  case MAIN_MENU_CLOSE_GAME_CODE:
    this->SetSignal(SCREEN_SIGNAL_SET, SCREEN_EXIT_NAME);
    break;
  }
}
