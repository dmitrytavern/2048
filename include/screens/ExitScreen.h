#pragma once
#include <iostream>
#include "libraries/Screen/Screen.h"

class ExitScreen : public Screen
{
private:
  using Screen::Screen;

public:
  void Render();
  void Run();
};
