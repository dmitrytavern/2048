#ifndef GAMEUI_H
#define GAMEUI_H

#include <iostream>
#include "Matrix.h"

class GameUI
{
public:
  void OutputTitle(std::string title);
  void OutputMatrix(Matrix &matrix);
  void OutputMatrixActions();
};

#endif
