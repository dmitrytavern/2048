#pragma once
#include "ScreenSignal.h"
#include <iostream>

class Screen
{
private:
  std::string name;
  ScreenSignal signal;

public:
  Screen(std::string name);
  std::string GetName();
  ScreenSignal GetSignal();
  void SetSignal(int signum);
  void SetSignal(int signum, std::string payload);
  virtual void Initialize();
  virtual void Terminate();
  virtual void Render();
  virtual void Run() = 0;
};
