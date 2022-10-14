#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

#include "libraries/Menu/Menu.h"
#include "libraries/Menu/MenuUI.h"
#include "libraries/UI/UI.h"

int MenuUI::BORDER_SIZE = 1;
int MenuUI::BORDER_WINDOW_PADDING = 3;

void MenuUI::PrintMenu(Menu *menu)
{
  string menu_title = menu->GetTitle();
  vector<MenuAction> menu_actions = menu->GetActions();
  int menu_actions_length = menu->GetActionsLength();

  int content_size = MenuUI::CalcContentSize(menu);
  int windows_size = MenuUI::CalcWindowsSize(content_size);
  int spaces_count = UI::CalcSpacesCount(windows_size);

  UI::PrintSpaces(spaces_count);
  UI::PrintWindowBorderTopWithTitle(windows_size, menu_title);

  for (int index = 0; index < menu_actions_length; index++)
  {
    string action_title = menu_actions[index].GetTitle();
    if (action_title != "")
    {
      UI::PrintSpaces(spaces_count);
      cout << UI::BORDER_VERTICAL_CHAR;
      UI::PrintSpaces(MenuUI::BORDER_WINDOW_PADDING);
      cout << std::left << setw(content_size) << action_title;
      UI::PrintSpaces(MenuUI::BORDER_WINDOW_PADDING);
      cout << UI::BORDER_VERTICAL_CHAR << endl;
    }
  }

  UI::PrintSpaces(spaces_count);
  UI::PrintWindowBorderBottom(windows_size);
}

int MenuUI::ActivateMenu(Menu *menu)
{
  int pressed_key = getch();
  menu->Trigger(pressed_key);
  return pressed_key;
}

int MenuUI::CalcContentSize(Menu *menu)
{
  vector<MenuAction> menu_actions = menu->GetActions();
  int menu_actions_length = menu->GetActionsLength();

  int max_content_length = 0;

  for (int index = 0; index < menu_actions_length; index++)
  {
    int length = menu_actions[index].GetTitle().length();
    max_content_length = length > max_content_length ? length : max_content_length;
  }

  return max_content_length;
}

int MenuUI::CalcWindowsSize(int content_size)
{
  return content_size + MenuUI::BORDER_WINDOW_PADDING * 2 + MenuUI::BORDER_SIZE * 2;
}
