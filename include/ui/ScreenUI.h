#ifndef SCREENUI_H
#define SCREENUI_H

#include <iostream>

using namespace std;

class ScreenUI
{
private:
  string *screens;
  unsigned int screens_length;
  string current_screen;

public:
  ScreenUI();
  void AddScreen(string screen);
  void SetScreen(string screen);
  bool ExistScreen(string screen);
  string GetCurrentScreen();
};

#endif
