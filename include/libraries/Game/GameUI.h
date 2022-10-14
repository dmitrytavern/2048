#pragma once
#include "./GameMatrix.h"

class GameUI
{
private:
  static int GetTerminalColorByNumber(int number);

public:
  static int BORDER_SIZE;
  static int CELL_WIDTH;
  static int CELL_HEIGHT;
  static int CELL_START_COLOR;

  static void OutputMatrix(GameMatrix *matrix);
  static int CalcOutputMatrixRow(int matrix_size);
  static int CalcOutputMatrixColumns(int matrix_size);
  static int CalcWindowsSize(int content_size);
};
