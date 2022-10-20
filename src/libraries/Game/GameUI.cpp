#include <iostream>
#include <iomanip>
#include <string>
#include "libraries/Game/GameMatrix.h"
#include "libraries/Game/GameUI.h"
#include "libraries/UI/UI.h"

using namespace std;

const int GameUI::BORDER_SIZE = 1;
const int GameUI::CELL_WIDTH = 5;
const int GameUI::CELL_HEIGHT = 3;
const int GameUI::CELL_START_COLOR = 40;

void GameUI::OutputMatrix(unsigned int **matrix, int matrix_size)
{
  unsigned int output_matrix_rows = GameUI::CalcOutputMatrixRow(matrix_size);
  unsigned int output_matrix_columns = GameUI::CalcOutputMatrixColumns(matrix_size);
  unsigned int windows_size = GameUI::CalcWindowsSize(output_matrix_columns);
  unsigned int spaces_count = UI::CalcSpacesCount(windows_size);

  string **chars_matrix;
  chars_matrix = new string *[output_matrix_rows];
  for (int row = 0; row < output_matrix_rows; row++)
    chars_matrix[row] = new string[output_matrix_columns];

  for (int row = 0; row < matrix_size; row++)
    for (int column = 0; column < matrix_size; column++)
    {
      int number = matrix[row][column];
      int number_row = row * GameUI::CELL_HEIGHT;
      int number_column = column * GameUI::CELL_WIDTH;
      int number_color = GameUI::GetTerminalColorByNumber(number);

      // Row 1
      chars_matrix[number_row + 0][number_column + 0] = number != 0 ? UI::PaintText(number_color, UI::BORDER_TOP_LEFT_CHAR) : " ";
      chars_matrix[number_row + 0][number_column + 1] = number != 0 ? UI::PaintText(number_color, UI::BORDER_HORIZONTAL_CHAR) : " ";
      chars_matrix[number_row + 0][number_column + 3] = number != 0 ? UI::PaintText(number_color, UI::BORDER_HORIZONTAL_CHAR) : " ";
      chars_matrix[number_row + 0][number_column + 2] = number != 0 ? UI::PaintText(number_color, UI::BORDER_HORIZONTAL_CHAR) : " ";
      chars_matrix[number_row + 0][number_column + 4] = number != 0 ? UI::PaintText(number_color, UI::BORDER_TOP_RIGHT_CHAR) : " ";

      // Row 2
      chars_matrix[number_row + 1][number_column + 0] = number != 0 ? UI::PaintText(number_color, UI::BORDER_VERTICAL_CHAR) : " ";
      chars_matrix[number_row + 1][number_column + 1] = number < 100 ? " " : "";
      chars_matrix[number_row + 1][number_column + 2] = number != 0 ? UI::PaintText(number_color, to_string(number)) : " ";
      chars_matrix[number_row + 1][number_column + 3] = number < 10 ? " " : "";
      chars_matrix[number_row + 1][number_column + 4] = number != 0 ? UI::PaintText(number_color, UI::BORDER_VERTICAL_CHAR) : " ";
      if (number > 999)
        chars_matrix[number_row + 1][number_column + 4] = "";
      if (number > 9999)
        chars_matrix[number_row + 1][number_column + 0] = "";

      // Row 3
      chars_matrix[number_row + 2][number_column + 0] = number != 0 ? UI::PaintText(number_color, UI::BORDER_BOTTOM_LEFT_CHAR) : " ";
      chars_matrix[number_row + 2][number_column + 1] = number != 0 ? UI::PaintText(number_color, UI::BORDER_HORIZONTAL_CHAR) : " ";
      chars_matrix[number_row + 2][number_column + 2] = number != 0 ? UI::PaintText(number_color, UI::BORDER_HORIZONTAL_CHAR) : " ";
      chars_matrix[number_row + 2][number_column + 3] = number != 0 ? UI::PaintText(number_color, UI::BORDER_HORIZONTAL_CHAR) : " ";
      chars_matrix[number_row + 2][number_column + 4] = number != 0 ? UI::PaintText(number_color, UI::BORDER_BOTTOM_RIGHT_CHAR) : " ";
    }

  UI::PrintSpaces(spaces_count);
  UI::PrintWindowBorderTop(windows_size);

  for (int row = 0; row < output_matrix_rows; row++)
  {
    UI::PrintSpaces(spaces_count);

    for (int column = 0; column < output_matrix_columns; column++)
    {
      if (column == 0)
        cout << UI::BORDER_VERTICAL_CHAR;

      cout << chars_matrix[row][column];

      if (column == output_matrix_columns - 1)
        cout << UI::BORDER_VERTICAL_CHAR;
    }

    cout << endl;
  }

  UI::PrintSpaces(spaces_count);
  UI::PrintWindowBorderBottom(windows_size);
}

int GameUI::CalcOutputMatrixRow(int matrix_size)
{
  return matrix_size * GameUI::CELL_HEIGHT;
}

int GameUI::CalcOutputMatrixColumns(int matrix_size)
{
  return matrix_size * GameUI::CELL_WIDTH;
}

int GameUI::CalcWindowsSize(int content_size)
{
  return content_size + GameUI::BORDER_SIZE * 2;
}

int GameUI::GetTerminalColorByNumber(int number)
{
  int color = GameUI::CELL_START_COLOR;

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
