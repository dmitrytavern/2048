#include <iostream>
#include <iomanip>
#include <string>
#include "UI/UI.h"
#include "Menu/Menu.h"
#include "Menu/MenuFactory.h"

vector<Menu> MenuFactory::menus = {};

Menu *MenuFactory::CreateMenu(string menu_name)
{
  if (MenuFactory::ExistsMenu(menu_name))
  {
    cout << "Error: menu " << menu_name << " already exists" << endl;
    exit(1);
  }

  MenuFactory::menus.push_back(*new Menu(menu_name));

  return &MenuFactory::menus[MenuFactory::menus.size() - 1];
}

Menu *MenuFactory::GetMenu(string screen)
{
  for (int index = 0; index < MenuFactory::menus.size(); index++)
    if (MenuFactory::menus[index].GetName() == screen)
      return &MenuFactory::menus[index];
  cout << "Error: menu not found" << endl;
  exit(1);
}

bool MenuFactory::ExistsMenu(string menu)
{
  for (int index = 0; index < MenuFactory::menus.size(); index++)
    if (MenuFactory::menus[index].GetName() == menu)
      return true;
  return false;
}
