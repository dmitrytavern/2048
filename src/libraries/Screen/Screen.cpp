#include <iostream>

#include "libraries/Screen/Screen.h"
#include "libraries/Screen/ScreenSignal.h"

using namespace std;

Screen::Screen(string screen_name)
{
  this->name = screen_name;
  this->signal = {0, ""};
}

string Screen::GetName()
{
  return this->name;
}

ScreenSignal Screen::GetSignal()
{
  return this->signal;
}

void Screen::SetSignal(int signum)
{
  this->signal = {signum, ""};
}

void Screen::SetSignal(int signum, string payload)
{
  this->signal = {signum, payload};
}
