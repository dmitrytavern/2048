#include <vector>
#include "global.h"
#include "interface/Interface.h"
#include "interface/BannerInterface.h"
#include "interface/WindowInterface.h"
#include "interface/TerminalInterface.h"
#include "interface/DialogInterface.h"
#include "screens/MainScreen.h"

enum Triggers
{
  MAIN_MENU_START_GAME_KEY = 97,
  MAIN_MENU_CLOSE_GAME_KEY = 101,
};

void MainScreen::Render()
{
  unsigned int menu_borders = Interface::Banner::BORDER_SIZE * 2 + 2;
  unsigned int other_print_rows = 8; // Title and \n

  Interface::Window::PrintVerticalAlign(menu_borders + other_print_rows);

  if (Interface::Terminal::GetTerminalWidth() >= 58)
  {
    Interface::Window::PrintCenter("  $$$$$$$\\   $$$$$$\\  $$\\      $$\\ $$$$$$$$\\ $$$$$$$\\ ");
    Interface::Window::PrintCenter("$$  __$$\\ $$  __$$\\ $$ | $\\  $$ |$$  _____|$$  __$$\\ ");
    Interface::Window::PrintCenter("$$ |  $$ |$$ /  $$ |$$ |$$$\\ $$ |$$ |      $$ |  $$ |");
    Interface::Window::PrintCenter("$$$$$$$  |$$ |  $$ |$$ $$ $$\\$$ |$$$$$\\    $$$$$$$  |");
    Interface::Window::PrintCenter("$$  ____/ $$ |  $$ |$$$$  _$$$$ |$$  __|   $$  __$$< ");
    Interface::Window::PrintCenter("$$ |       $$$$$$  |$$  /   \\$$ |$$$$$$$$\\ $$ |  $$ |");
    Interface::Window::PrintCenter("\\__|       \\______/ \\__/     \\__|\\________|\\__|  \\__|");
  }
  else
  {
    Interface::Window::PrintCenter("Power");
  }

  Interface::Print();

  Interface::Banner::Print("Main", {"a - start game",
                                    "e - close game"});
}

void MainScreen::Run()
{
  bool dialog = true;

  while (dialog)
  {
    const int code = Interface::Dialog::GetCharCode();

    switch (code)
    {
    case MAIN_MENU_START_GAME_KEY:
      this->SetSignal(SCREEN_SIGNAL_SET, SCREEN_GAME_NAME);
      dialog = false;
      break;

    case MAIN_MENU_CLOSE_GAME_KEY:
      this->SetSignal(SCREEN_SIGNAL_SET, SCREEN_EXIT_NAME);
      dialog = false;
      break;
    }
  }
}
