#pragma once
#include <iostream>

class MenuAction
{
private:
  int trigger;
  std::string title;
  std::function<void()> callback;

public:
  std::string GetTitle();
  int GetTrigger();
  void SetTitle(std::string title);
  void SetTrigger(int code);
  void SetCallback(std::function<void()>);
  void Execute();
};
