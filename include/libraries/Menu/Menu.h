#pragma once
#include <iostream>
#include <functional>
#include "MenuAction.h"

using namespace std;

class Menu
{
private:
  string title;
  vector<MenuAction> actions;

public:
  Menu();
  string GetTitle();
  void SetTitle(string title);
  void Trigger(int trigger);
  void AddAction(int trigger, string title, function<void()>);
  int GetActionsLength();
  vector<MenuAction> &GetActions();
};
