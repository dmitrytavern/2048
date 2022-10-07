#include <iostream>
#include <iomanip>
#include <conio.h>
#include "./src/GameUI.cpp"
#include "./src/GameMatrix.cpp"
#include "./src/GameMatrixActions.cpp"
#include "./src/Menu.cpp"

GameUI ui;
Menu ui_menu_main;
Menu ui_menu_game;

void SetGameMenu()
{
  ui.SetMenu(ui_menu_game);
}

void Exit()
{
  exit(0);
}

int main()
{
  srand(time(0));
  setlocale(LC_ALL, "");

  GameMatrix matrix(4);
  GameMatrixActions controls(matrix);

  ui_menu_main.AddAction(97, "a - start game", &SetGameMenu);

  ui_menu_game.AddAction(119, "w - swipe to up", std::bind(&GameMatrixActions::SwipeUp, controls));
  ui_menu_game.AddAction(97, "a - swipe to left", std::bind(&GameMatrixActions::SwipeLeft, controls));
  ui_menu_game.AddAction(115, "s - swipe to down", std::bind(&GameMatrixActions::SwipeDown, controls));
  ui_menu_game.AddAction(100, "d - swipe to right", std::bind(&GameMatrixActions::SwipeRight, controls));
  ui_menu_game.AddAction(119, "", std::bind(&GameMatrixActions::FillRandomCell, controls));
  ui_menu_game.AddAction(97, "", std::bind(&GameMatrixActions::FillRandomCell, controls));
  ui_menu_game.AddAction(115, "", std::bind(&GameMatrixActions::FillRandomCell, controls));
  ui_menu_game.AddAction(100, "", std::bind(&GameMatrixActions::FillRandomCell, controls));
  ui_menu_game.AddAction(101, "e - exit", &Exit);

  ui.SetTitle("2048 Game");
  ui.SetMatrix(matrix);
  ui.SetMenu(ui_menu_main);

  controls.FillRandomCell();

  while (1)
  {
    system("clear");

    if (matrix.GetEmptyCellCount() == 0)
    {
      ui.SetTitle("Game Over");
      ui.OutputTitle();
      ui.OutputMatrix();
      break;
    }

    ui.OutputTitle();
    ui.OutputMatrix();
    ui.OutputMenu();
    ui.ActivateMenu();
  }
}
