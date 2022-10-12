#ifndef GAMEUI_H
#define GAMEUI_H

#include "./GameMatrix.h"

class GameUI
{
private:
  static int cell_start_color;
  static int GetTerminalColorByNumber(int number);

public:
  static void OutputMatrix(GameMatrix *matrix);
};

#endif
