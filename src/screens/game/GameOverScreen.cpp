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
  unsigned int matrix_size = Core::Matrix::GetSize();
  unsigned int matrix_cell_height = Interface::Matrix::CELL_HEIGHT;
  unsigned int matrix_borders = Interface::Matrix::BORDER_SIZE * 2;
  unsigned int menu_borders = Interface::Banner::BORDER_SIZE * 2;
  unsigned int matrix_print_rows = matrix_size * matrix_cell_height + matrix_borders;
  unsigned int menu_print_rows = menu_borders + 2;
  unsigned int other_print_rows = 2; // Result, Title

  Interface::Window::OutputVerticalAlign(matrix_print_rows + menu_print_rows + other_print_rows);

#ifdef __linux__
  Interface::Window::OutputCenter("━━━━ 2048 Game Session ━━━━", 28);
#else
  Interface::Window::OutputCenter("---- 2048 Game Session ----");
#endif

  Interface::Window::OutputCenter("Your result: " + std::to_string(Core::Score::Get()));

  Interface::Matrix::Output(Core::Matrix::Get(), Core::Matrix::GetSize());

  Interface::Banner::Output("Game Over", {"a - new game",
                                          "e - close game"});

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
