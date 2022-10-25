#include <string>
#include "global.h"
#include "core/Core.h"
#include "core/CoreMatrix.h"
#include "core/CoreScore.h"
#include "interface/Interface.h"
#include "interface/TerminalInterface.h"
#include "interface/BannerInterface.h"
#include "interface/WindowInterface.h"
#include "interface/MatrixInterface.h"
#include "interface/DialogInterface.h"
#include "interface/TitleInterface.h"
#include "screens/game/GamePlayScreen.h"

void GamePlayScreen::Initialize()
{
  Core::ToStartGame();
}

void GamePlayScreen::Render()
{
  std::string score = std::to_string(Core::Score::Get());

  Interface::Title::OutputGameTitle();
  Interface::Output();

  Interface::Window::OutputCenter("Your score: " + score);

  Interface::Matrix::Output(Core::Matrix::Get(), Core::Matrix::GetSize());

  Interface::Banner::Output("Control", {"w - swipe to up",
                                        "a - swipe to left",
                                        "s - swipe to down",
                                        "d - swipe to right",
                                        "e - exit"});

  Interface::Window::AlignVertically();
  Interface::Terminal::Clear();
  Interface::Print();
}

void GamePlayScreen::Run()
{
  bool dialog = true;

  while (dialog)
  {
    const int code = Interface::Dialog::GetCharCode();

    switch (code)
    {
    case Interface::Dialog::KEY_UP:
    case Interface::Dialog::CHAR_W:
      Core::ToMove(Core::Matrix::SWIPE_DIRECTION_UP);
      dialog = false;
      break;

    case Interface::Dialog::KEY_LEFT:
    case Interface::Dialog::CHAR_A:
      Core::ToMove(Core::Matrix::SWIPE_DIRECTION_LEFT);
      dialog = false;
      break;

    case Interface::Dialog::KEY_DOWN:
    case Interface::Dialog::CHAR_S:
      Core::ToMove(Core::Matrix::SWIPE_DIRECTION_DOWN);
      dialog = false;
      break;

    case Interface::Dialog::KEY_RIGHT:
    case Interface::Dialog::CHAR_D:
      Core::ToMove(Core::Matrix::SWIPE_DIRECTION_RIGHT);
      dialog = false;
      break;

    case Interface::Dialog::CHAR_E:
      this->SetSignal(SCREEN_SIGNAL_EXIT);
      dialog = false;
      break;
    }
  }

  if (!Core::Matrix::ExistsMove())
    this->SetSignal(SCREEN_SIGNAL_SET, SCREEN_GAME_OVER_NAME);
}
