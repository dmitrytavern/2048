#include <conio.h>
#include <string>
#include "../../include/ui/MenuUI.h"

MenuUI::MenuUI(UI &ui)
{
  this->ui = &ui;
  this->menus = new Menu[0];
  this->menus_length = 0;
  this->current_menu_exists = false;
}

void MenuUI::AddMenu(Menu &menu)
{
  if (this->ExistMenu(menu.GetName()))
  {
    cout << "Error: menu " << menu.GetName() << " already exists" << endl;
    return;
  }

  this->menus_length++;

  Menu *temp = new Menu[this->menus_length];

  std::copy(this->menus, this->menus + this->menus_length - 1, temp);

  delete[] this->menus;

  this->menus = temp;
  this->menus[this->menus_length - 1] = menu;
}

void MenuUI::SetMenu(string menu)
{
  if (!this->ExistMenu(menu))
  {
    cout << "Error: menu " << menu << " not exists" << endl;
    return;
  }

  this->current_menu = this->GetMenuByName(menu);
  this->current_menu_exists = true;
}

bool MenuUI::ExistMenu(string menu)
{
  for (int index = 0; index < this->menus_length; index++)
    if (this->menus[index].GetName() == menu)
      return true;
  return false;
}

bool MenuUI::ExistCurrentMenu()
{
  return this->current_menu_exists;
}

string MenuUI::GetCurrentMenu()
{
  if (this->current_menu_exists)
  {
    return this->current_menu->GetName();
  }
  else
  {
    cout << "Error: current menu not setted" << endl;
    exit(1);
  }
}

void MenuUI::Output()
{
  if (this->current_menu_exists)
  {
    MenuAction *actions = this->current_menu->GetActions();
    int actions_length = this->current_menu->GetActionsLength();
    int centered_chars_count = this->ui->GetTerminalSize()->ws_col / 2;
    int window_length = 0;
    int content_length = 0;
    int padding_length = 3;
    int border_length = 1;

    for (int index = 0; index < actions_length; index++)
    {
      int length = actions[index].GetTitle().length();
      content_length = length > content_length ? length : content_length;
    }

    window_length += content_length + padding_length * 2 + border_length * 2;
    centered_chars_count -= window_length / 2;

    this->ui->OutputSpaces(centered_chars_count);
    this->ui->OutputBorderTop(window_length, this->current_menu->GetTitle());

    for (int index = 0; index < actions_length; index++)
      if (actions[index].GetTitle() != "")
      {
        this->ui->OutputSpaces(centered_chars_count);
        cout << "│";
        this->ui->OutputSpaces(padding_length);
        cout << std::left << setw(content_length) << actions[index].GetTitle();
        this->ui->OutputSpaces(padding_length);
        cout << "│" << endl;
      }

    this->ui->OutputSpaces(centered_chars_count);
    this->ui->OutputBorderBottom(window_length);
  }
  else
  {
    cout << "Error: current menu not setted" << endl;
    exit(1);
  }
}

void MenuUI::Activate()
{
  if (this->current_menu_exists)
  {
    int pressed_key = getch();
    this->current_menu->Trigger(pressed_key);
  }
  else
  {
    cout << "Error: current menu not setted" << endl;
    exit(1);
  }
}

Menu *MenuUI::GetMenuByName(string screen)
{
  for (int index = 0; index < this->menus_length; index++)
    if (this->menus[index].GetName() == screen)
      return &this->menus[index];
  exit(1);
}
