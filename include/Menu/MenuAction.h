#ifndef MENUACTION_H
#define MENUACTION_H

#include <iostream>
#include <functional>

using namespace std;

class MenuAction
{
private:
  int trigger;
  string title;
  function<void()> callback;

public:
  string GetTitle();
  int GetTrigger();
  void SetTitle(string title);
  void SetTrigger(int code);
  void SetCallback(function<void()>);
  void Execute();
};

#endif