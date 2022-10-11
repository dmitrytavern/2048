#ifndef SCREENUI_H
#define SCREENUI_H

#include <iostream>
#include <functional>
#include "./Screen.h"

using namespace std;

class ScreenUI
{
private:
  Screen *current_screen;
  bool current_screen_exists;
  bool screen_ui_exit;

public:
  ScreenUI();
  void SetScreen(Screen *screen);
  bool ExistCurrentScreen();
  string GetCurrentScreen();
  void Output();
  void Exit();
};

#endif
