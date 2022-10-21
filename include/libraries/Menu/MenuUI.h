#pragma once
#include <iostream>

class MenuUI
{
public:
  static const int BORDER_SIZE;
  static const int BORDER_WINDOW_PADDING;

  static void PrintMenu(std::string title, std::vector<std::string> actions);
  static int CalcContentSize(std::vector<std::string>);
  static int CalcWindowsSize(int content_size);
};
