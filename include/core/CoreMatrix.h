#pragma once
#include <iostream>
#include "GameMatrix.h"

namespace Core
{
  namespace Matrix
  {
    static GameMatrix *matrix;
    static bool exists_matrix;

    unsigned int **Get();
    unsigned int GetSize();
    unsigned int GetEmptyCellCount();
    void FillCell(int number);
    void Swipe(std::string direction);
    void Create();
    void Clear();
    void Exists();
  }
}
