#include "../include/Screen.h"

string Screen::GetName()
{
  return this->name;
}

void Screen::SetName(string name)
{
  this->name = name;
}

void Screen::SetFunction(function<void()> fn)
{
  this->fn = fn;
}

void Screen::Execute()
{
  this->fn();
}
