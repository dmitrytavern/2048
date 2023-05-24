#include "../../include/screens/ExitScreen.h"
#include "../../include/global.h"
#include "../../include/interface/DialogInterface.h"
#include "../../include/interface/Interface.h"
#include "../../include/interface/TerminalInterface.h"
#include "../../include/interface/TitleInterface.h"
#include "../../include/interface/WindowInterface.h"

void ExitScreen::Render()
{
  Interface::Title::OutputMainTitle();
  Interface::Output("\n\n");

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
