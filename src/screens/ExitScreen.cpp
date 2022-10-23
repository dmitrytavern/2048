#include "global.h"
#include "core/Core.h"
#include "interface/Interface.h"
#include "interface/WindowInterface.h"
#include "interface/DialogInterface.h"
#include "screens/ExitScreen.h"
#include "screens/game/GamePlayScreen.h"
#include "screens/game/GameOverScreen.h"

ExitScreen::ExitScreen() : Screen(SCREEN_EXIT_NAME)
{
  this->fn_exit = [&]() -> void
  {
    this->SetSignal(SCREEN_SIGNAL_EXIT);
  };

  this->fn_back = [&]() -> void
  {
    this->SetSignal(SCREEN_SIGNAL_SET, SCREEN_MAIN_NAME);
  };
}

void ExitScreen::Render()
{
  Interface::Window::PrintVerticalAlign(2);
  Interface::Window::PrintCenter("Exit from game?");
  Interface::Window::PrintCenter("[Y/n]");
}

void ExitScreen::Run()
{
  const bool comfirm = Interface::Dialog::GetComfirm();

  if (comfirm)
  {
    this->fn_exit();
  }
  else
  {
    this->fn_back();
  }
}
