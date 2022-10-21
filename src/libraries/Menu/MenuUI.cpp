#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "libraries/Menu/MenuUI.h"
#include "libraries/UI/UI.h"

using namespace std;

const int MenuUI::BORDER_SIZE = 1;
const int MenuUI::BORDER_WINDOW_PADDING = 3;

void MenuUI::PrintMenu(string title, vector<string> actions)
{
  int menu_actions_length = actions.size();
  int content_size = MenuUI::CalcContentSize(actions);
  int windows_size = MenuUI::CalcWindowsSize(content_size);
  int spaces_count = UI::CalcSpacesCount(windows_size);

  UI::PrintSpaces(spaces_count);
  UI::PrintWindowBorderTopWithTitle(windows_size, title);

  for (int index = 0; index < menu_actions_length; index++)
  {
    string action_title = actions[index];
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

int MenuUI::CalcContentSize(vector<string> actions)
{
  int menu_actions_length = actions.size();
  int max_content_length = 0;

  for (int index = 0; index < menu_actions_length; index++)
  {
    int length = actions[index].length();
    max_content_length = length > max_content_length ? length : max_content_length;
  }

  return max_content_length;
}

int MenuUI::CalcWindowsSize(int content_size)
{
  return content_size + MenuUI::BORDER_WINDOW_PADDING * 2 + MenuUI::BORDER_SIZE * 2;
}
