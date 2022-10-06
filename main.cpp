#include <iostream>
#include <conio.h>
#include "./src/Matrix.cpp"
#include "./src/MatrixActions.cpp"

#define KEY_UP 119
#define KEY_DOWN 115
#define KEY_LEFT 97
#define KEY_RIGHT 100
#define KEY_EXIT 101

void show_control_menu();

int main()
{
  srand(time(0));

  Matrix matrix(4);
  MatrixActions controls(matrix);

  while (1)
  {
    system("clear");

    controls.FillRandomCell();

    if (matrix.GetEmptyCellCount() == 0)
    {
      std::cout << "Game over" << std::endl;
      matrix.OutputMatrix();
      break;
    }

    std::cout << "Game:" << std::endl;

    matrix.OutputMatrix();

    show_control_menu();

    switch (getch())
    {
    case KEY_UP:
      controls.SwipeUp();
      break;

    case KEY_DOWN:
      controls.SwipeDown();
      break;

    case KEY_LEFT:
      controls.SwipeLeft();
      break;

    case KEY_RIGHT:
      controls.SwipeRight();
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

void show_control_menu()
{
  std::cout << "w - swipe to up" << std::endl;
  std::cout << "a - swipe to left" << std::endl;
  std::cout << "s - swipe to down" << std::endl;
  std::cout << "d - swipe to right" << std::endl;
  std::cout << "e - exit" << std::endl;
}
