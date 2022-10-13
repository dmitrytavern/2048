#include <iostream>
#include "Screen/Screen.h"

using namespace std;

Screen::Screen(ScreenStore *app_screen_store, ScreenManager *app_screen_manager)
{
  this->app_screen_store = app_screen_store;
  this->app_screen_manager = app_screen_manager;
}
