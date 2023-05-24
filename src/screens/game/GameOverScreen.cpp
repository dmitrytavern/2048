#include "../../../include/screens/game/GameOverScreen.h"
#include "../../../include/core/Core.h"
#include "../../../include/core/CoreMatrix.h"
#include "../../../include/core/CoreScore.h"
#include "../../../include/global.h"
#include "../../../include/interface/BannerInterface.h"
#include "../../../include/interface/DialogInterface.h"
#include "../../../include/interface/Interface.h"
#include "../../../include/interface/MatrixInterface.h"
#include "../../../include/interface/TerminalInterface.h"
#include "../../../include/interface/TitleInterface.h"
#include "../../../include/interface/WindowInterface.h"
#include <iostream>
#include <string>

void GameOverScreen::Render()
{
  std::string score = std::to_string(Core::Score::Get());

  Interface::Title::OutputGameTitle();
  Interface::Output();

  Interface::Window::OutputCenter("Your result: " + score);

  Interface::Matrix::Output(Core::Matrix::Get(), Core::Matrix::GetSize());

  Interface::Banner::Output("Game Over", {"a - new game", "e - close game"});

  Interface::Window::AlignVertically();
  Interface::Terminal::Clear();
  Interface::Print();
}

void GameOverScreen::Run()
{
  bool dialog = true;

  while (dialog)
  {
    const int code = Interface::Dialog::GetCharCode();

    switch (code)
    {
    case Interface::Dialog::CHAR_A:
    case Interface::Dialog::CHAR_A_UPPER:
      this->SetSignal(SCREEN_SIGNAL_SET, SCREEN_GAME_PLAY_NAME);
      dialog = false;
      break;

    case Interface::Dialog::CHAR_E:
    case Interface::Dialog::CHAR_E_UPPER:
    case Interface::Dialog::KEY_ESC:
      this->SetSignal(SCREEN_SIGNAL_EXIT);
      dialog = false;
      break;
    }
  }
}
