#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <functional>
#include "./MenuAction.h"

using namespace std;

class Menu
{
private:
  string name;
  string title;
  MenuAction *actions;
  unsigned int actions_length;

public:
  Menu(string name);
  string GetName();
  string GetTitle();
  void SetTitle(string name);
  void Trigger(int trigger);
  void AddAction(int trigger, string title, function<void()>);
  int GetActionsLength();
  MenuAction *GetActions();
};

#endif
