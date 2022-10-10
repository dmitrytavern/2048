#ifndef MENUFACTORY_H
#define MENUFACTORY_H

#include "Menu.h"
#include "vector"

using namespace std;

class MenuFactory
{
private:
  static vector<Menu> menus;

public:
  static Menu *CreateMenu(string menu_name);
  static Menu *GetMenu(string menu_name);
  static bool ExistsMenu(string menu_name);
};

#endif