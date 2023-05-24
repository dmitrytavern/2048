#pragma once
#include "../libraries/Menu/Menu.h"
#include "../libraries/Screen/Screen.h"
#include <iostream>
#include <vector>

struct AboutItem
{
  std::string column_name;
  std::string column_value;
  unsigned int color;
};

class AboutScreen : public Screen
{
private:
  static unsigned int COLUMNS_INDENT;
  static unsigned int COLOR_TITLE;
  static unsigned int COLOR_ITEM;

  Menu *screen_menu;
  std::vector<AboutItem> data;
  int window_spaces;
  int column_name_width;
  int column_value_width;

  void AddSplit();
  void AddRow(std::string column_name);
  void AddRow(std::string column_name, std::string column_value);

public:
  AboutScreen();
  void Render();
  void Run();
  void CalculateSpaces();
  void CalculateWindowSize();
};
