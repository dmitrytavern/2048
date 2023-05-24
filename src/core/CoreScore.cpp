#include <iostream>

namespace Core::Score
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
} // namespace Core::Score
