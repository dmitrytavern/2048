#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <functional>

using namespace std;

class Screen
{
private:
  string name;
  function<void()> ui_function;
  function<void()> action_function;

public:
  Screen(string name);
  string GetName();
  void SetUIFunction(function<void()> fn);
  void SetActionFunction(function<void()> fn);
  void RunUI();
  void RunAction();
};

#endif