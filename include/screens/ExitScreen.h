#pragma once
#include "../libraries/Screen/Screen.h"
#include <iostream>

class ExitScreen : public Screen
{
private:
  using Screen::Screen;

public:
  void Render();
  void Run();
};
