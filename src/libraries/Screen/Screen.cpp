#include <iostream>
#include "Screen/Screen.h"

using namespace std;

Screen::Screen(ScreenManager *app_screen_manager)
{
  this->app_screen_manager = app_screen_manager;
}
