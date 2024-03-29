#include "../../include/core/Core.h"
#include "../../include/core/CoreMatrix.h"
#include "../../include/core/CoreScore.h"
#include <iostream>

namespace Core
{
void ToStartGame()
{
  Core::Matrix::Create();
  Core::Score::Clear();
  Next();
  Next();
}

void ToMove(Core::Matrix::SwipeDirections direction)
{
  Core::Matrix::Swipe(direction);
  Next();
}

void ToFinishGame()
{
  Core::Matrix::Clear();
  Core::Score::Clear();
}

static void Next()
{
  if (Core::Matrix::GetEmptyCellCount() != 0)
  {
    int number = GenerateNumber();
    Core::Score::Increment(number);
    Core::Matrix::FillCell(number);
  }
}

static int GenerateNumber()
{
  if (Core::Score::Get() >= 128)
    return (std::rand() % (2 - 1 + 1) + 1) * 2;
  return 2;
}
} // namespace Core
