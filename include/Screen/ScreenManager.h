#ifndef SCREENUI_H
#define SCREENUI_H

#include <iostream>
#include "./Screen.h"

using namespace std;

class ScreenManager
{
private:
  Screen *current_screen;
  bool current_screen_exists;
  bool ui_exit;
  void WindowsResizeHandler();

public:
  ScreenManager();
  void Set(Screen *screen);
  void Run();
  void Exit();
  bool ExistsActiveScreen();
  Screen *GetActiveScreen();
};

#endif
