#pragma once

class GameMatrix
{
private:
  unsigned int size;
  unsigned int **matrix;

  void CompareCells(unsigned int *previous_cell, unsigned int *current_cell);
  bool ExistCompareCells(unsigned int *previous_cell, unsigned int *current_cell);

public:
  GameMatrix(unsigned int size);
  void SwipeUp();
  void SwipeLeft();
  void SwipeDown();
  void SwipeRight();
  void FillRandomCell(int number);
  bool ExistCompareRowCells();
  bool ExistCompareColumnCells();
  unsigned int **GetMatrix();
  unsigned int GetMatrixSize();
  unsigned int GetEmptyCellCount();
};
