#pragma once
#include <iostream>
#include <functional>
#include <vector>
#include "MenuAction.h"

class Menu
{
private:
  std::string title;
  std::vector<MenuAction> actions;

public:
  Menu();
  std::string GetTitle();
  void SetTitle(std::string title);
  void Trigger(int trigger);
  void AddAction(int trigger, std::string title, std::function<void()>);
  int GetActionsLength();
  std::vector<std::string> GetActionNames();
  static int ActivateMenu(Menu *menu);
};
