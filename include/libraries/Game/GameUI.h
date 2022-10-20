#pragma once

class GameUI
{
private:
  static int GetTerminalColorByNumber(int number);

public:
  static const int BORDER_SIZE;
  static const int CELL_WIDTH;
  static const int CELL_HEIGHT;
  static const int CELL_START_COLOR;

  static void OutputMatrix(unsigned int **matrix, const int matrix_size);
  static int CalcOutputMatrixRow(int matrix_size);
  static int CalcOutputMatrixColumns(int matrix_size);
  static int CalcWindowsSize(int content_size);
};
