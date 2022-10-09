#ifndef GAMEUI_H
#define GAMEUI_H

#include <iostream>
#include "../GameMatrix.h"

using namespace std;

class GameUI
{
private:
  UI *ui;
  GameMatrix *matrix;
  int cell_start_color;
  int GetTerminalColorByNumber(int number);

public:
  GameUI(UI &ui);
  void SetMatrix(GameMatrix &matrix);
  void SetCellStartColor(int color);
  void OutputMatrix();
};

#endif
