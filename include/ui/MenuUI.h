#ifndef MENUUI_H
#define MENUUI_H

#include <iostream>
#include "../Menu.h"

using namespace std;

class MenuUI
{
private:
  Menu *menus;
  Menu *current_menu;
  bool current_menu_exists;
  unsigned int menus_length;
  Menu *GetMenuByName(string menu_name);

public:
  MenuUI();
  void AddMenu(Menu &menu);
  void SetMenu(string menu_name);
  bool ExistMenu(string menu_name);
  bool ExistCurrentMenu();
  string GetCurrentMenu();
  void Output();
  void Activate();
};

#endif
