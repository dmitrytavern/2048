#pragma once
#include <iostream>

namespace Core
{
  void ToStartGame();
  void ToFinishGame();
  void ToMove(std::string direction);
  bool ExistsMove();

  static int GenerateNumber();
}
