#ifndef GAMEUI_H
#define GAMEUI_H

#include <iostream>
#include "GameMatrix.h"

class GameUI
{
private:
  std::string title;
  GameMatrix *matrix;

public:
  void SetTitle(std::string title);
  void SetMatrix(GameMatrix &matrix);
  void OutputTitle();
  void OutputMatrix();
  void OutputMatrixActions();
};

#endif
