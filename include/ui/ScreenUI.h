#ifndef SCREENUI_H
#define SCREENUI_H

#include <iostream>
#include "../Screen.h"

using namespace std;

class ScreenUI
{
private:
  Screen *screens;
  Screen *current_screen;
  bool current_screen_exists;
  unsigned int screens_length;
  bool screen_ui_exit;

  Screen *GetScreenByName(string screen);

public:
  ScreenUI();
  void AddScreen(string screen, function<void()> screen_function);
  void SetScreen(string screen);
  bool ExistScreen(string screen);
  bool ExistCurrentScreen();
  string GetCurrentScreen();
  void Output();
  void Exit();
};

#endif
