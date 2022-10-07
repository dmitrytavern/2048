#ifndef MENUUI_H
#define MENUUI_H

#include <iostream>
#include "../Menu.h"

using namespace std;

class MenuUI
{
private:
  Menu *menu;

public:
  void SetMenu(Menu &menu);
  void OutputMenu();
  void ActivateMenu();
};

#endif
