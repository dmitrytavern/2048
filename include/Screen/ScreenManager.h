#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <iostream>
#include "Screen.h"

using namespace std;

class Screen;
class ScreenManager
{
private:
  Screen *current_screen;
  bool current_screen_exists;
  bool ui_exit;
  void WindowsResizeHandler();

public:
  ScreenManager();
  void Set(string screen_name);
  void Run();
  void Exit();
  bool ExistsActiveScreen();
};

#endif
