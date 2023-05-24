#pragma once
#include "../../libraries/Screen/Screen.h"
#include <iostream>

class GameOverScreen : public Screen
{
private:
  using Screen::Screen;

public:
  void Render();
  void Run();
};
