#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include "ScreenStore.h"
#include "ScreenManager.h"

using namespace std;

class ScreenStore;
class ScreenManager;
class Screen
{
protected:
  ScreenStore *app_screen_store;
  ScreenManager *app_screen_manager;

public:
  Screen(ScreenStore *app_screen_store, ScreenManager *app_screen_manager);
  virtual string GetName() = 0;
  virtual void Initialize() = 0;
  virtual void Graphic() = 0;
  virtual void Action() = 0;
  virtual void Exit() = 0;
};

#endif