#pragma once
#include "vector"
#include "Screen.h"

using namespace std;

class Screen;
class ScreenStore
{
private:
  vector<Screen *> screens;

public:
  ScreenStore();
  void AddScreen(Screen *screen);
  Screen *GetScreen(string screen_name);
  bool ExistsScreen(string screen_name);
};
