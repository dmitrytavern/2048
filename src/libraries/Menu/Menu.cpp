#include <iostream>
#include "libraries/Menu/Menu.h"
#include "libraries/Menu/MenuAction.h"

using namespace std;

Menu::Menu()
{
  this->actions = {};
}

void Menu::SetTitle(string title)
{
  this->title = title;
}

string Menu::GetTitle()
{
  return this->title;
}

int Menu::GetActionsLength()
{
  return this->actions.size();
}

vector<string> Menu::GetActionNames()
{
  vector<string> titles;
  for (int index = 0; index < this->GetActionsLength(); index++)
    titles.push_back(this->actions[index].GetTitle());
  return titles;
}

void Menu::AddAction(int trigger, string title, function<void()> callback)
{
  int index = this->GetActionsLength();
  this->actions.push_back(*new MenuAction);
  this->actions[index].SetTitle(title);
  this->actions[index].SetTrigger(trigger);
  this->actions[index].SetCallback(callback);
}

void Menu::Trigger(int trigger)
{
  for (int action_index = 0; action_index < this->GetActionsLength(); action_index++)
    if (this->actions[action_index].GetTrigger() == trigger)
      this->actions[action_index].Execute();
}
