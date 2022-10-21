#pragma once
#include <iostream>
#include <vector>

namespace Interface::Menu
{
  const int BORDER_SIZE = 1;
  const int BORDER_WINDOW_PADDING = 3;

  void Print(std::string title, std::vector<std::string> actions);
  static int CalcContentSize(std::vector<std::string>);
  static int CalcWindowSize(int content_size);
}
