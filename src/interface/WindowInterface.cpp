#include <iostream>
#include "interface/Interface.h"
#include "interface/WindowInterface.h"
#include "interface/TerminalInterface.h"

using namespace std;

namespace Interface::Window
{
  void PrintCenter(string message)
  {
    unsigned int length = message.length();
    unsigned int spaces_count = CalcSpacesCount(length);

    Interface::PrintSpaces(spaces_count);
    Interface::Print(message);
    Interface::Print();
  }

  void PrintCenter(string message, int message_length)
  {
    unsigned int spaces_count = CalcSpacesCount(message_length);

    Interface::PrintSpaces(spaces_count);
    Interface::Print(message);
    Interface::Print();
  }

  void PrintVerticalAlign(int content_row_count)
  {
    unsigned int window_height = Interface::Terminal::GetTerminalHeight();
    unsigned int length = (window_height - content_row_count) / 2;
    string n = "";

    for (int i = 0; i < length; i++)
      n += "\n";

    Interface::Print(n);
  }

  void PrintBorderTop(int chars_count)
  {
    for (int index = 0; index < chars_count; index++)
      if (index == 0)
        Interface::Print(BORDER_TOP_LEFT_CHAR);
      else if (index == chars_count - 1)
        Interface::Print(BORDER_TOP_RIGHT_CHAR);
      else
        Interface::Print(BORDER_HORIZONTAL_CHAR);

    Interface::Print();
  }

  void PrintBorderTopWithTitle(int chars_count, string title)
  {
    int title_length = title.length();
    int start_print_index = chars_count / 2 - title_length / 2;

    for (int index = 1; index <= chars_count; index++)
      if (index == 1)
      {
        Interface::Print(BORDER_TOP_LEFT_CHAR);
      }
      else if (index == chars_count)
      {
        Interface::Print(BORDER_TOP_RIGHT_CHAR);
      }
      else if (index == start_print_index)
      {
        Interface::Print(" " + title + " ");
        index += title_length + 1;
      }
      else
      {
        Interface::Print(BORDER_HORIZONTAL_CHAR);
      }

    Interface::Print();
  }

  void PrintBorderBottom(int count)
  {
    for (int index = 0; index < count; index++)
      if (index == 0)
        Interface::Print(BORDER_BOTTOM_LEFT_CHAR);
      else if (index == count - 1)
        Interface::Print(BORDER_BOTTOM_RIGHT_CHAR);
      else
        Interface::Print(BORDER_HORIZONTAL_CHAR);

    Interface::Print();
  }

  unsigned int CalcSpacesCount(int windows_size)
  {
    return Interface::Terminal::GetTerminalWidth() / 2 - windows_size / 2;
  }
}
