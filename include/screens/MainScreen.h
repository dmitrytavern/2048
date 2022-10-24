#pragma once
#include <iostream>
#include "libraries/Screen/Screen.h"

class MainScreen : public Screen
{
private:
  using Screen::Screen;

public:
  void Render();
  void Run();
};
