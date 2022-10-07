#ifndef GAMEUI_H
#define GAMEUI_H

#include <iostream>
#include "GameMatrix.h"

class GameUI
{
private:
  std::string title;
  GameMatrix *matrix;
  int cell_start_color;
  int GetTerminalColorByNumber(int number);

public:
  GameUI();
  void SetTitle(std::string title);
  void SetMatrix(GameMatrix &matrix);
  void SetCellStartColor(int color);
  void OutputTitle();
  void OutputMatrix();
  void OutputMatrixActions();
};

#endif
