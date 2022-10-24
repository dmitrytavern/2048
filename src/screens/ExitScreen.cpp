#include "global.h"
#include "interface/Interface.h"
#include "interface/WindowInterface.h"
#include "interface/DialogInterface.h"
#include "screens/ExitScreen.h"

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
    this->SetSignal(SCREEN_SIGNAL_EXIT);
  else
    this->SetSignal(SCREEN_SIGNAL_SET, SCREEN_MAIN_NAME);
}
