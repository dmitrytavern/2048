#include <iostream>
#include <iomanip>
#include <functional>
#include <conio.h>
#include "./src/GameMatrix.cpp"
#include "./src/GameMatrixActions.cpp"
#include "./src/Menu.cpp"
#include "./src/ui/GameUI.cpp"
#include "./src/ui/MenuUI.cpp"

#define KEY_UP 119
#define KEY_LEFT 97
#define KEY_DOWN 115
#define KEY_RIGHT 100
#define KEY_EXIT 101

GameUI ui_game;
MenuUI ui_menu;
Menu ui_menu_main;
Menu ui_menu_game;

void SetGameMenu()
{
  ui_menu.SetMenu(ui_menu_game);
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

  ui_menu_game.AddAction(KEY_UP, "w - swipe to up", std::bind(&GameMatrixActions::SwipeUp, controls));
  ui_menu_game.AddAction(KEY_LEFT, "a - swipe to left", std::bind(&GameMatrixActions::SwipeLeft, controls));
  ui_menu_game.AddAction(KEY_DOWN, "s - swipe to down", std::bind(&GameMatrixActions::SwipeDown, controls));
  ui_menu_game.AddAction(KEY_RIGHT, "d - swipe to right", std::bind(&GameMatrixActions::SwipeRight, controls));
  ui_menu_game.AddAction(KEY_UP, "", std::bind(&GameMatrixActions::FillRandomCell, controls));
  ui_menu_game.AddAction(KEY_LEFT, "", std::bind(&GameMatrixActions::FillRandomCell, controls));
  ui_menu_game.AddAction(KEY_DOWN, "", std::bind(&GameMatrixActions::FillRandomCell, controls));
  ui_menu_game.AddAction(KEY_RIGHT, "", std::bind(&GameMatrixActions::FillRandomCell, controls));
  ui_menu_game.AddAction(KEY_EXIT, "e - exit", &Exit);

  ui_game.SetTitle("2048 Game");
  ui_game.SetMatrix(matrix);
  ui_menu.SetMenu(ui_menu_main);

  controls.FillRandomCell();

  while (1)
  {
    system("clear");

    if (matrix.GetEmptyCellCount() == 0)
    {
      ui_game.SetTitle("Game Over");
      ui_game.OutputTitle();
      ui_game.OutputMatrix();
      break;
    }

    ui_game.OutputTitle();
    ui_game.OutputMatrix();
    ui_menu.OutputMenu();
    ui_menu.ActivateMenu();
  }
}
