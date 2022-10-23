#pragma once
#include <iostream>
#include "libraries/Screen/Screen.h"
#include "libraries/Menu/Menu.h"

class ExitScreen : public Screen
{
private:
  std::function<void()> fn_exit;
  std::function<void()> fn_back;

public:
  ExitScreen();
  void Render();
  void Run();
};
