#include "global.h"
#include "interface/Interface.h"
#include "interface/TerminalInterface.h"
#include "interface/WindowInterface.h"
#include "interface/DialogInterface.h"
#include "screens/ExitScreen.h"

void ExitScreen::Render()
{
  Interface::Window::OutputCenter("Exit from game?");
  Interface::Window::OutputCenter("[Y/n]");

  Interface::Window::AlignVertically();
  Interface::Terminal::Clear();
  Interface::Print();
}

void ExitScreen::Run()
{
  const bool comfirm = Interface::Dialog::GetComfirm();

  if (comfirm)
    this->SetSignal(SCREEN_SIGNAL_EXIT);
  else
    this->SetSignal(SCREEN_SIGNAL_SET, SCREEN_MAIN_NAME);
}
