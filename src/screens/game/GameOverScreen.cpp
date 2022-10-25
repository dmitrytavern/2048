#include <iostream>
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
#include "screens/game/GameOverScreen.h"

void GameOverScreen::Render()
{
#ifdef __linux__
  Interface::Window::OutputCenter("━━━━ 2048 Game Session ━━━━", 28);
#else
  Interface::Window::OutputCenter("---- 2048 Game Session ----");
#endif

  Interface::Window::OutputCenter("Your result: " + std::to_string(Core::Score::Get()));

  Interface::Matrix::Output(Core::Matrix::Get(), Core::Matrix::GetSize());

  Interface::Banner::Output("Game Over", {"a - new game",
                                          "e - close game"});

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
      this->SetSignal(SCREEN_SIGNAL_SET, SCREEN_GAME_PLAY_NAME);
      dialog = false;
      break;

    case Interface::Dialog::CHAR_E:
      this->SetSignal(SCREEN_SIGNAL_EXIT);
      dialog = false;
      break;
    }
  }
}
