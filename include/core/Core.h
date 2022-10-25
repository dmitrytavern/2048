#pragma once
#include <iostream>
#include "CoreMatrix.h"

namespace Core
{
  void ToStartGame();
  void ToFinishGame();
  void ToMove(Core::Matrix::SwipeDirections direction);

  static void Next();
  static int GenerateNumber();
}
