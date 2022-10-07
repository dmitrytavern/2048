#ifndef GAMEUI_H
#define GAMEUI_H

#include <iostream>
#include "GameMatrix.h"
#include "Menu.h"

using namespace std;

class GameUI
{
private:
  string title;
  Menu *menu;
  GameMatrix *matrix;
  int cell_start_color;
  int GetTerminalColorByNumber(int number);

public:
  GameUI();
  void SetMenu(Menu &menu);
  void SetTitle(string title);
  void SetMatrix(GameMatrix &matrix);
  void SetCellStartColor(int color);
  void OutputTitle();
  void OutputMatrix();
  void OutputMenu();
  void ActivateMenu();
};

#endif
