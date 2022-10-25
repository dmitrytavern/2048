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
  Menu *screen_menu;
  std::vector<AboutItem> data;

public:
  AboutScreen();
  void Render();
  void Run();
};
