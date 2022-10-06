#include <iostream>
#include <iomanip>
#include "../include/GameUI.h"
#include "../include/GameMatrix.h"

using namespace std;

void GameUI::OutputTitle(string title)
{
  cout << title << endl;
}

void GameUI::OutputMatrix(GameMatrix &matrix)
{
  unsigned int matrix_size = matrix.GetMatrixSize();
  unsigned int chars_matrix_rows = matrix_size * 3;
  unsigned int chars_matrix_columns = matrix_size * 5;
  unsigned int border_columns = matrix_size * 5 + 2;

  unsigned int **int_matrix = matrix.GetMatrix();
  string chars_matrix[chars_matrix_rows][chars_matrix_columns];

  for (int row = 0; row < matrix_size; row++)
    for (int column = 0; column < matrix_size; column++)
    {
      int color = 0;

      switch (int_matrix[row][column])
      {
      case 2:
        color = 31;
        break;
      case 4:
        color = 32;
        break;
      case 8:
        color = 33;
        break;
      case 16:
        color = 34;
        break;
      case 32:
        color = 35;
        break;
      case 64:
        color = 36;
        break;
      case 128:
        color = 37;
        break;
      case 256:
        color = 90;
        break;
      case 512:
        color = 91;
        break;
      case 1024:
        color = 92;
        break;
      case 2048:
        color = 92;
        break;
      default:
        break;
      }

      // Row 1
      chars_matrix[row * 3 + 0][column * 5 + 0] = int_matrix[row][column] != 0 ? "\033[1;" + to_string(color) + "m┌\033[0m" : " ";
      chars_matrix[row * 3 + 0][column * 5 + 1] = int_matrix[row][column] != 0 ? "\033[1;" + to_string(color) + "m─\033[0m" : " ";
      chars_matrix[row * 3 + 0][column * 5 + 3] = int_matrix[row][column] != 0 ? "\033[1;" + to_string(color) + "m─\033[0m" : " ";
      chars_matrix[row * 3 + 0][column * 5 + 2] = int_matrix[row][column] != 0 ? "\033[1;" + to_string(color) + "m─\033[0m" : " ";
      chars_matrix[row * 3 + 0][column * 5 + 4] = int_matrix[row][column] != 0 ? "\033[1;" + to_string(color) + "m┐\033[0m" : " ";

      // Row 2
      chars_matrix[row * 3 + 1][column * 5 + 0] = int_matrix[row][column] != 0 ? "\033[1;" + to_string(color) + "m│\033[0m" : " ";
      if (int_matrix[row][column] > 9999)
        chars_matrix[row * 3 + 1][column * 5 + 0] = "";

      chars_matrix[row * 3 + 1][column * 5 + 1] = int_matrix[row][column] < 100 ? " " : "";
      chars_matrix[row * 3 + 1][column * 5 + 2] = int_matrix[row][column] != 0 ? "\033[1;" + to_string(color) + "m" + to_string(int_matrix[row][column]) + "\033[0m" : " ";
      chars_matrix[row * 3 + 1][column * 5 + 3] = int_matrix[row][column] < 10 ? " " : "";
      chars_matrix[row * 3 + 1][column * 5 + 4] = int_matrix[row][column] != 0 ? "\033[1;" + to_string(color) + "m│\033[0m" : " ";
      if (int_matrix[row][column] > 999)
        chars_matrix[row * 3 + 1][column * 5 + 4] = "";

      // Row 3
      chars_matrix[row * 3 + 2][column * 5 + 0] = int_matrix[row][column] != 0 ? "\033[1;" + to_string(color) + "m└\033[0m" : " ";
      chars_matrix[row * 3 + 2][column * 5 + 1] = int_matrix[row][column] != 0 ? "\033[1;" + to_string(color) + "m─\033[0m" : " ";
      chars_matrix[row * 3 + 2][column * 5 + 2] = int_matrix[row][column] != 0 ? "\033[1;" + to_string(color) + "m─\033[0m" : " ";
      chars_matrix[row * 3 + 2][column * 5 + 3] = int_matrix[row][column] != 0 ? "\033[1;" + to_string(color) + "m─\033[0m" : " ";
      chars_matrix[row * 3 + 2][column * 5 + 4] = int_matrix[row][column] != 0 ? "\033[1;" + to_string(color) + "m┘\033[0m" : " ";
    }

  for (int column = 0; column < border_columns; column++)
  {
    if (column == 0)
      cout << "┌";
    else if (column == border_columns - 1)
      cout << "┐";
    else
      cout << "─";
  }

  cout << endl;

  for (int row = 0; row < chars_matrix_rows; row++)
  {
    for (int column = 0; column < chars_matrix_columns; column++)
    {
      if (column == 0)
        cout << "│";

      cout << chars_matrix[row][column];

      if (column == chars_matrix_columns - 1)
        cout << "│";
    }

    cout << endl;
  }

  for (int column = 0; column < border_columns; column++)
  {
    if (column == 0)
      cout << "└";
    else if (column == border_columns - 1)
      cout << "┘";
    else
      cout << "─";
  }

  cout << endl;
}

void GameUI::OutputMatrixActions()
{
  cout << "w - swipe to up" << endl;
  cout << "a - swipe to left" << endl;
  cout << "s - swipe to down" << endl;
  cout << "d - swipe to right" << endl;
  cout << "e - exit" << endl;
}
