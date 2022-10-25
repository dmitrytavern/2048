#pragma once
#include <iostream>
#include <vector>
#include "libraries/Screen/Screen.h"
#include "libraries/Menu/Menu.h"

struct AboutItem
{
  std::string column_name;
  std::string column_value;
};

class AboutScreen : public Screen
{
private:
  static unsigned int COLUMNS_INDENT;

  Menu *screen_menu;
  std::vector<AboutItem> data;
  int window_spaces;
  int column_name_width;
  int column_value_width;

public:
  AboutScreen();
  void Render();
  void Run();
  void CalculateSpaces();
  void CalculateWindowSize();
};
