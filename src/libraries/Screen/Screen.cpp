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

void Screen::SetFunction(function<void()> fn)
{
  this->fn = fn;
}

void Screen::Execute()
{
  this->fn();
}
