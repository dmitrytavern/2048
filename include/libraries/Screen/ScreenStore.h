#pragma once
#include <iostream>
#include <vector>
#include "Screen.h"

class ScreenStore
{
private:
  std::vector<Screen *> screens;

public:
  ScreenStore();
  void AddScreen(Screen *screen);
  Screen *GetScreen(std::string screen_name);
  bool ExistsScreen(std::string screen_name);
};
