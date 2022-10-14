#pragma once
#include <iostream>
#include "ScreenSignal.h"

using namespace std;

class Screen
{
private:
  string name;
  ScreenSignal signal;

public:
  Screen(string name);
  string GetName();
  ScreenSignal GetSignal();
  void SetSignal(int signum);
  void SetSignal(int signum, string payload);
  virtual void Initialize() = 0;
  virtual void Terminate() = 0;
  virtual void Graphics() = 0;
  virtual void Run() = 0;
};
