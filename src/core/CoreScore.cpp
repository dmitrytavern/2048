#include <iostream>

namespace Core
{
  namespace Score
  {
    static int score;

    int Get()
    {
      return score;
    }

    void Clear()
    {
      score = 0;
    }

    void Increment(int number)
    {
      score += number;
    }
  }
}
