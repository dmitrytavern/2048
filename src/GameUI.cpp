#include <iostream>
#include <iomanip>
#include "../include/GameUI.h"
#include "../include/GameMatrix.h"
#include "../include/Menu.h"

using namespace std;

GameUI::GameUI()
{
  this->cell_start_color = 40;
}

void GameUI::SetTitle(string title)
{
  this->title = title;
}

void GameUI::SetMatrix(GameMatrix &matrix)
{
  this->matrix = &matrix;
}

void GameUI::SetCellStartColor(int color)
{
  this->cell_start_color = color;
}

void GameUI::OutputTitle()
{
  cout << this->title << endl;
}

void GameUI::OutputMatrix()
{
  unsigned int matrix_size = this->matrix->GetMatrixSize();
  unsigned int chars_matrix_rows = matrix_size * 3;
  unsigned int chars_matrix_columns = matrix_size * 5;
  unsigned int border_columns = matrix_size * 5 + 2;

  unsigned int **int_matrix = this->matrix->GetMatrix();
  string chars_matrix[chars_matrix_rows][chars_matrix_columns];

  for (int row = 0; row < matrix_size; row++)
    for (int column = 0; column < matrix_size; column++)
    {
      int number = int_matrix[row][column];
      int color = this->GetTerminalColorByNumber(number);

      // Row 1
      chars_matrix[row * 3 + 0][column * 5 + 0] = number != 0 ? "\033[38:5:" + to_string(color) + "m┌\033[0m" : " ";
      chars_matrix[row * 3 + 0][column * 5 + 1] = number != 0 ? "\033[38:5:" + to_string(color) + "m─\033[0m" : " ";
      chars_matrix[row * 3 + 0][column * 5 + 3] = number != 0 ? "\033[38:5:" + to_string(color) + "m─\033[0m" : " ";
      chars_matrix[row * 3 + 0][column * 5 + 2] = number != 0 ? "\033[38:5:" + to_string(color) + "m─\033[0m" : " ";
      chars_matrix[row * 3 + 0][column * 5 + 4] = number != 0 ? "\033[38:5:" + to_string(color) + "m┐\033[0m" : " ";

      // Row 2
      chars_matrix[row * 3 + 1][column * 5 + 0] = number != 0 ? "\033[38:5:" + to_string(color) + "m│\033[0m" : " ";
      if (number > 9999)
        chars_matrix[row * 3 + 1][column * 5 + 0] = "";

      chars_matrix[row * 3 + 1][column * 5 + 1] = number < 100 ? " " : "";
      chars_matrix[row * 3 + 1][column * 5 + 2] = number != 0 ? "\033[38:5:" + to_string(color) + "m" + to_string(number) + "\033[0m" : " ";
      chars_matrix[row * 3 + 1][column * 5 + 3] = number < 10 ? " " : "";
      chars_matrix[row * 3 + 1][column * 5 + 4] = number != 0 ? "\033[38:5:" + to_string(color) + "m│\033[0m" : " ";
      if (number > 999)
        chars_matrix[row * 3 + 1][column * 5 + 4] = "";

      // Row 3
      chars_matrix[row * 3 + 2][column * 5 + 0] = number != 0 ? "\033[38:5:" + to_string(color) + "m└\033[0m" : " ";
      chars_matrix[row * 3 + 2][column * 5 + 1] = number != 0 ? "\033[38:5:" + to_string(color) + "m─\033[0m" : " ";
      chars_matrix[row * 3 + 2][column * 5 + 2] = number != 0 ? "\033[38:5:" + to_string(color) + "m─\033[0m" : " ";
      chars_matrix[row * 3 + 2][column * 5 + 3] = number != 0 ? "\033[38:5:" + to_string(color) + "m─\033[0m" : " ";
      chars_matrix[row * 3 + 2][column * 5 + 4] = number != 0 ? "\033[38:5:" + to_string(color) + "m┘\033[0m" : " ";
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

void GameUI::SetMenu(Menu &menu)
{
  this->menu = &menu;
}

void GameUI::OutputMenu()
{
  MenuAction *actions = this->menu->GetActions();
  int actions_length = this->menu->GetActionsLength();

  for (int index = 0; index < actions_length; index++)
    if (actions[index].GetTitle() != "")
      cout << actions[index].GetTitle() << endl;
}

void GameUI::ActivateMenu()
{
  int pressed_key = getch();
  this->menu->Trigger(pressed_key);
}

int GameUI::GetTerminalColorByNumber(int number)
{
  int color = this->cell_start_color;

  for (int i = 1; number > 2; i++)
  {
    number = number / 2;

    if (i % 6 == 0)
      color += 67;
    else
      color += 1;
  }

  if (color > 255)
    color = 255;

  return color;
}
