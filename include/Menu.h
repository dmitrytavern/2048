#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "./GameController.h"
#include "./MenuAction.h"

using namespace std;

class Menu
{
private:
  string name;
  MenuAction *actions;
  unsigned int actions_length;

public:
  Menu();
  string GetName();
  void SetName(string name);
  void Trigger(int trigger);
  void AddAction(int trigger, string title, function<void()>);
  int GetActionsLength();
  MenuAction *GetActions();
};

#endif
