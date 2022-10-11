#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <functional>

using namespace std;

class Screen
{
private:
  string name;
  function<void()> fn;

public:
  Screen(string name);
  string GetName();
  void SetFunction(function<void()> fn);
  void Execute();
};

#endif