#include <conio.h>
#include "../../include/ui/MenuUI.h"

void MenuUI::SetMenu(Menu &menu)
{
  this->menu = &menu;
}

void MenuUI::OutputMenu()
{
  MenuAction *actions = this->menu->GetActions();
  int actions_length = this->menu->GetActionsLength();

  for (int index = 0; index < actions_length; index++)
    if (actions[index].GetTitle() != "")
      cout << actions[index].GetTitle() << endl;
}

void MenuUI::ActivateMenu()
{
  int pressed_key = getch();
  this->menu->Trigger(pressed_key);
}
