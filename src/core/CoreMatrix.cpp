#include <iostream>
#include "core/GameMatrix.h"

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

    unsigned int **Get()
    {
      return matrix->GetMatrix();
    }

    unsigned int GetSize()
    {
      return matrix->GetMatrixSize();
    }

    unsigned int GetEmptyCellCount()
    {
      return matrix->GetEmptyCellCount();
    }

    void FillCell(int number)
    {
      matrix->FillRandomCell(number);
    }

    void Create()
    {
      matrix = new GameMatrix(4);
      exists_matrix = true;
    }

    void Clear()
    {
      exists_matrix = false;
      delete matrix;
    }

    bool Exists()
    {
      return exists_matrix;
    }

    void Swipe(SwipeDirections direction)
    {
      if (direction == SWIPE_DIRECTION_UP)
        matrix->SwipeUp();

      if (direction == SWIPE_DIRECTION_LEFT)
        matrix->SwipeLeft();

      if (direction == SWIPE_DIRECTION_DOWN)
        matrix->SwipeDown();

      if (direction == SWIPE_DIRECTION_RIGHT)
        matrix->SwipeRight();
    }
  }
}
