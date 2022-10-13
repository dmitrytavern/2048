#include <iostream>

#include "libraries/Screen/Screen.h"

using namespace std;

Screen::Screen(string screen_name, ScreenStore *app_screen_store, ScreenManager *app_screen_manager)
{
  this->name = screen_name;
  this->app_screen_store = app_screen_store;
  this->app_screen_manager = app_screen_manager;
}

string Screen::GetName()
{
  return this->name;
}
