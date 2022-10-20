#pragma once
#include <iostream>
#include "core/Core.h"
#include "core/CoreMatrix.h"
#include "core/CoreScore.h"

namespace Core
{
  void ToStartGame()
  {
    int number = GenerateNumber();
    Core::Matrix::Create();
    Core::Matrix::FillCell(number);
    Core::Score::Increment(number);
  }

  void ToFinishGame()
  {
    Core::Matrix::Clear();
    Core::Score::Clear();
  }

  void ToMove(std::string direction)
  {
    int number = GenerateNumber();
    Core::Score::Increment(number);
    Core::Matrix::FillCell(number);
    Core::Matrix::Swipe(direction);
  }

  bool ExistsMove()
  {
    return Core::Matrix::GetEmptyCellCount() != 0;
  }

  static int GenerateNumber()
  {
    if (Core::Score::Get() >= 128)
      return (std::rand() % (2 - 1 + 1) + 1) * 2;
    return 2;
  }
}
