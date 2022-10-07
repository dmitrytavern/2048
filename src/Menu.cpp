#include <iostream>
#include <functional>
#include "../include/Menu.h"
#include "../include/MenuAction.h"
#include "../src/MenuAction.cpp"

using namespace std;

Menu::Menu()
{
  this->actions_length = 0;
  this->actions = new MenuAction[0];
}

void Menu::AddAction(int trigger, string title, function<void()> callback)
{
  this->actions_length++;

  MenuAction *temp = new MenuAction[this->actions_length];

  std::copy(this->actions, this->actions + this->actions_length - 1, temp);

  delete[] this->actions;

  this->actions = temp;

  this->actions[this->actions_length - 1] = *new MenuAction();
  this->actions[this->actions_length - 1].SetTitle(title);
  this->actions[this->actions_length - 1].SetTrigger(trigger);
  this->actions[this->actions_length - 1].SetCallback(callback);
}

MenuAction *Menu::GetActions()
{
  return this->actions;
}

int Menu::GetActionsLength()
{
  return this->actions_length;
}

void Menu::Trigger(int trigger)
{
  MenuAction action;

  for (int action_index = 0; action_index < this->actions_length; action_index++)
  {
    action = this->actions[action_index];

    if (action.GetTrigger() == trigger)
      action.Execute();
  }
}
