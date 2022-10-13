#include <iostream>

#include "libraries/Menu/Menu.h"
#include "libraries/Menu/MenuAction.h"

using namespace std;

Menu::Menu()
{
  this->actions = {};
}

string Menu::GetTitle()
{
  return this->title;
}

void Menu::SetTitle(string title)
{
  this->title = title;
}

void Menu::AddAction(int trigger, string title, function<void()> callback)
{
  int index = this->GetActionsLength();
  this->actions.push_back(*new MenuAction);
  this->actions[index].SetTitle(title);
  this->actions[index].SetTrigger(trigger);
  this->actions[index].SetCallback(callback);
}

vector<MenuAction> &Menu::GetActions()
{
  return this->actions;
}

int Menu::GetActionsLength()
{
  return this->actions.size();
}

void Menu::Trigger(int trigger)
{
  for (int action_index = 0; action_index < this->GetActionsLength(); action_index++)
    if (this->actions[action_index].GetTrigger() == trigger)
      this->actions[action_index].Execute();
}
