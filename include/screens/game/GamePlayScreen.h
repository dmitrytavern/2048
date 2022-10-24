#pragma once
#include <iostream>
#include "libraries/Screen/Screen.h"

class GamePlayScreen : public Screen
{
private:
  using Screen::Screen;

public:
  void Initialize();
  void Render();
  void Run();
};
