#ifndef GAMEMATRIXACTIONS_H
#define GAMEMATRIXACTIONS_H

#include "GameMatrix.h"

class GameMatrixActions
{
private:
  GameMatrix *matrix;

  void CompareCells(unsigned int *previous_cell, unsigned int *current_cell);
  bool ExistCompareCells(unsigned int *previous_cell, unsigned int *current_cell);

public:
  GameMatrixActions(GameMatrix &matrix);
  void SwipeUp();
  void SwipeLeft();
  void SwipeDown();
  void SwipeRight();
  void FillRandomCell();
};

#endif
