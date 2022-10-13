#pragma once
#include <iostream>
#include "ScreenStore.h"
#include "ScreenManager.h"

using namespace std;

class ScreenStore;
class ScreenManager;
class Screen
{
protected:
  string name;
  ScreenStore *app_screen_store;
  ScreenManager *app_screen_manager;

public:
  Screen(string name, ScreenStore *app_screen_store, ScreenManager *app_screen_manager);
  string GetName();
  virtual void Initialize() = 0;
  virtual void Graphic() = 0;
  virtual void Action() = 0;
  virtual void Exit() = 0;
};
