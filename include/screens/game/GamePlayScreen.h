#pragma once
#include "../../libraries/Screen/Screen.h"
#include <iostream>

class GamePlayScreen : public Screen
{
private:
  using Screen::Screen;

public:
  void Initialize();
  void Render();
  void Run();
};
