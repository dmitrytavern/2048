#ifndef GAMEUI_H
#define GAMEUI_H

#include <iostream>
#include "GameMatrix.h"

class GameUI
{
public:
  void OutputTitle(std::string title);
  void OutputMatrix(GameMatrix &matrix);
  void OutputMatrixActions();
};

#endif
