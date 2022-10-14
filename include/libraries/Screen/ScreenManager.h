#pragma once
#include <iostream>
#include "Screen.h"
#include "ScreenSignal.h"

using namespace std;

class ScreenManager
{
private:
  Screen *current_screen;
  ScreenStore *app_screen_store;
  bool current_screen_exists;
  bool ui_exit;
  void WindowsResizeHandler();

public:
  ScreenManager(ScreenStore *app_screen_store);
  void Set(Screen *screen);
  void Run();
  void Exit();
  void SendSignal(ScreenSignal signal);
  bool ExistsActiveScreen();
};
