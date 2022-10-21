#include <iostream>
#include "core/Core.h"
#include "core/CoreMatrix.h"
#include "core/CoreScore.h"

namespace Core
{
  void ToStartGame()
  {
    Core::Matrix::Create();
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

  bool ExistsMove()
  {
    return Core::Matrix::GetEmptyCellCount() != 0;
  }

  static void Next()
  {
    int number = GenerateNumber();
    Core::Score::Increment(number);
    Core::Matrix::FillCell(number);
  }

  static int GenerateNumber()
  {
    if (Core::Score::Get() >= 128)
      return (std::rand() % (2 - 1 + 1) + 1) * 2;
    return 2;
  }
}
