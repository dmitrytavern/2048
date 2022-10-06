#ifndef MATRIXACTIONS_H
#define MATRIXACTIONS_H

#include "Matrix.h"

class MatrixActions
{
private:
  Matrix *matrix;

  void CompareCells(unsigned int *previous_cell, unsigned int *current_cell);
  bool ExistCompareCells(unsigned int *previous_cell, unsigned int *current_cell);

public:
  MatrixActions(Matrix &matrix);
  void SwipeUp();
  void SwipeLeft();
  void SwipeDown();
  void SwipeRight();
  void FillRandomCell();
};

#endif
