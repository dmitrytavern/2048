#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include "ScreenManager.h"

using namespace std;

class ScreenManager;
class Screen
{
protected:
  ScreenManager *app_screen_manager;

public:
  Screen(ScreenManager *app_screen_manager);
  virtual string GetName() = 0;
  virtual void Initialize() = 0;
  virtual void Graphic() = 0;
  virtual void Action() = 0;
  virtual void Exit() = 0;
};

#endif