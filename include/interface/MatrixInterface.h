#pragma once

namespace Interface::Matrix
{
  const int BORDER_SIZE = 1;
  const int CELL_WIDTH = 5;
  const int CELL_HEIGHT = 3;
#ifdef __linux__
  const int CELL_START_COLOR = 40;
#else
  const int CELL_START_COLOR = 31;
#endif

  void Output(unsigned int **matrix, const int matrix_size);
  static int CalcMatrixRow(int matrix_size);
  static int CalcMatrixColumns(int matrix_size);
  static int CalcWindowSize(int content_size);
  static int GetTerminalColorByNumber(int number);
}
