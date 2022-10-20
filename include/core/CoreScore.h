#pragma once
#include <iostream>

namespace Core
{
  namespace Score
  {
    static int score;

    int Get();
    void Clear();
    void Increment(int number);
  }
}
