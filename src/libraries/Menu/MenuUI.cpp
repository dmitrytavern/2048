#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

#include "libraries/Menu/Menu.h"
#include "libraries/Menu/MenuUI.h"
#include "libraries/UI/UI.h"

void MenuUI::PrintMenu(Menu *menu)
{
  MenuAction *actions = menu->GetActions();
  int actions_length = menu->GetActionsLength();
  int centered_chars_count = UI::GetTerminalWidth() / 2;
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

  UI::PrintSpaces(centered_chars_count);
  UI::PrintWindowBorderTopWithTitle(window_length, menu->GetTitle());

  for (int index = 0; index < actions_length; index++)
    if (actions[index].GetTitle() != "")
    {
      UI::PrintSpaces(centered_chars_count);
      cout << UI::BORDER_VERTICAL_CHAR;
      UI::PrintSpaces(padding_length);
      cout << std::left << setw(content_length) << actions[index].GetTitle();
      UI::PrintSpaces(padding_length);
      cout << UI::BORDER_VERTICAL_CHAR << endl;
    }

  UI::PrintSpaces(centered_chars_count);
  UI::PrintWindowBorderBottom(window_length);
}

void MenuUI::ActivateMenu(Menu *menu)
{
  int pressed_key = getch();
  menu->Trigger(pressed_key);
}
