#pragma once
#include <iostream>
#include <functional>
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
  std::vector<MenuAction> &GetActions();
};
