#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "./GameMatrixActions.h"
#include "./MenuAction.h"

using namespace std;

class Menu
{
private:
  MenuAction *actions;
  unsigned int actions_length;

public:
  Menu();
  void Trigger(int trigger);
  void AddAction(int trigger, string title, function<void()>);
  int GetActionsLength();
  MenuAction *GetActions();
};

#endif
