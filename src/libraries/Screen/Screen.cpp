#include <iostream>
#include <functional>
#include "Screen/Screen.h"

using namespace std;

Screen::Screen(string name)
{
  this->name = name;
}

string Screen::GetName()
{
  return this->name;
}

void Screen::SetUIFunction(function<void()> fn)
{
  this->ui_function = fn;
}

void Screen::SetActionFunction(function<void()> fn)
{
  this->action_function = fn;
}

void Screen::RunUI()
{
  this->ui_function();
}

void Screen::RunAction()
{
  this->action_function();
}
