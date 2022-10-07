#include <iostream>
#include <iomanip>
#include <conio.h>
#include "./src/GameUI.cpp"
#include "./src/GameMatrix.cpp"
#include "./src/GameMatrixActions.cpp"

#define KEY_UP 119
#define KEY_DOWN 115
#define KEY_LEFT 97
#define KEY_RIGHT 100
#define KEY_EXIT 101

int main()
{
  srand(time(0));
  setlocale(LC_ALL, "");

  GameUI ui;
  GameMatrix matrix(4);
  GameMatrixActions controls(matrix);

  controls.FillRandomCell();

  while (1)
  {
    system("clear");

    if (matrix.GetEmptyCellCount() == 0)
    {
      ui.OutputTitle("Game Over");
      ui.OutputMatrix(matrix);
      break;
    }

    ui.OutputTitle("2048 Game");
    ui.OutputMatrix(matrix);
    ui.OutputMatrixActions();

    switch (getch())
    {
    case KEY_UP:
      controls.SwipeUp();
      controls.FillRandomCell();

      break;

    case KEY_DOWN:
      controls.SwipeDown();
      controls.FillRandomCell();

      break;

    case KEY_LEFT:
      controls.SwipeLeft();
      controls.FillRandomCell();

      break;

    case KEY_RIGHT:
      controls.SwipeRight();
      controls.FillRandomCell();

      break;

    case KEY_EXIT:
      std::cout << "Exiting..." << std::endl;
      exit(0);
      break;

    default:
      std::cout << "Char not found. If you want to exit, press 'e'" << std::endl;
    }
  }
}
