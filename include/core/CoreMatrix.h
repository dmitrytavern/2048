#pragma once
#include <iostream>
#include "GameMatrix.h"

namespace Core
{
  namespace Matrix
  {
    static GameMatrix *matrix;
    static bool exists_matrix;

    enum SwipeDirections
    {
      SWIPE_DIRECTION_UP,
      SWIPE_DIRECTION_LEFT,
      SWIPE_DIRECTION_DOWN,
      SWIPE_DIRECTION_RIGHT,
    };

    unsigned int **Get();
    unsigned int GetSize();
    unsigned int GetEmptyCellCount();
    void FillCell(int number);
    void Swipe(SwipeDirections direction);
    void Create();
    void Clear();
    void Exists();
  }
}
