#pragma once
#include <iostream>
#include <functional>
#include "Screen.h"
#include "ScreenSignal.h"

class ScreenManager
{
private:
  static ScreenManager *currect_manager;

  Screen *current_screen;
  ScreenStore *app_screen_store;
  bool current_screen_exists;
  bool ui_exit;

public:
  static ScreenManager *GetCurrectManager();

  ScreenManager(ScreenStore *app_screen_store);
  void Set(Screen *screen);
  void Run();
  void Exit();
  void RenderActiveScreen();
  bool ExistsActiveScreen();
  void SendSignal(ScreenSignal signal);
};
