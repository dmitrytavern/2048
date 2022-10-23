#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "interface/Interface.h"
#include "interface/MenuInterface.h"
#include "interface/WindowInterface.h"

using namespace std;

namespace Interface::Menu
{
  void Print(string title, vector<string> actions)
  {
    int actions_size = actions.size();
    int content_size = CalcContentSize(actions);
    int window_size = CalcWindowSize(content_size);
    int spaces_count = Interface::Window::CalcSpacesCount(window_size);

    Interface::PrintSpaces(spaces_count);
    Interface::Window::PrintBorderTopWithTitle(window_size, title);

    for (int index = 0; index < actions_size; index++)
    {
      if (actions[index] != "")
      {
        Interface::PrintSpaces(spaces_count);
        Interface::Print(Interface::Window::BORDER_VERTICAL_CHAR);
        Interface::PrintSpaces(BORDER_WINDOW_PADDING);
        printf(((string)("%-" + to_string(content_size) + "s")).c_str(), actions[index].c_str());
        Interface::PrintSpaces(BORDER_WINDOW_PADDING);
        Interface::Print(Interface::Window::BORDER_VERTICAL_CHAR);
        Interface::Print();
      }
    }

    Interface::PrintSpaces(spaces_count);
    Interface::Window::PrintBorderBottom(window_size);
  }

  static int CalcContentSize(vector<string> actions)
  {
    int actions_size = actions.size();
    int max_content_length = 0;

    for (int index = 0; index < actions_size; index++)
    {
      int length = actions[index].length();
      max_content_length = length > max_content_length ? length : max_content_length;
    }

    return max_content_length;
  }

  static int CalcWindowSize(int content_size)
  {
    return content_size + BORDER_WINDOW_PADDING * 2 + BORDER_SIZE * 2;
  }
}