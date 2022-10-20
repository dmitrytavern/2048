#include <iostream>
#include "core/GameMatrix.h"

namespace Core
{
  namespace Matrix
  {
    static GameMatrix *matrix;
    static bool exists_matrix;

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

    void Swipe(std::string direction)
    {
      if (direction == "up")
        matrix->SwipeUp();

      if (direction == "left")
        matrix->SwipeLeft();

      if (direction == "down")
        matrix->SwipeDown();

      if (direction == "right")
        matrix->SwipeRight();
    }

    bool Exists()
    {
      return exists_matrix;
    }
  }
}
