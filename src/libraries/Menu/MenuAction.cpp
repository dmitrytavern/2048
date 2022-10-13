#include <iostream>
#include <functional>

#include "libraries/Menu/MenuAction.h"

int MenuAction::GetTrigger()
{
  return this->trigger;
}

string MenuAction::GetTitle()
{
  return this->title;
}

void MenuAction::SetTitle(string title)
{
  this->title = title;
}

void MenuAction::SetTrigger(int code)
{
  this->trigger = code;
}

void MenuAction::SetCallback(std::function<void()> callback)
{
  this->callback = callback;
}

void MenuAction::Execute()
{
  this->callback();
}
