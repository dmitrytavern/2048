#include <iostream>
#include <string.h>
#include "interface/Interface.h"
#include "interface/WindowInterface.h"
#include "interface/TerminalInterface.h"

using namespace std;

namespace Interface::Window
{
  void OutputCenter(string message)
  {
    unsigned int length = message.length();
    unsigned int spaces_count = CalcSpacesCount(length);

    Interface::OutputSpaces(spaces_count);
    Interface::Output(message);
    Interface::Output();
  }

  void OutputCenter(string message, int message_length)
  {
    unsigned int spaces_count = CalcSpacesCount(message_length);

    Interface::OutputSpaces(spaces_count);
    Interface::Output(message);
    Interface::Output();
  }

  void AlignVertically()
  {
    unsigned int window_height = Interface::Terminal::GetHeight();
    unsigned int content_row_count = std::count(output.begin(), output.end(), '\n');
    int length = content_row_count < window_height ? ((window_height - content_row_count) / 2) : 0;

    string n = "";
    for (int i = 0; i < length; i++)
      n += "\n";

    OutputInStart(n);
  }

  void PrintBorderTop(int chars_count)
  {
    for (int index = 0; index < chars_count; index++)
      if (index == 0)
        Interface::Output(BORDER_TOP_LEFT_CHAR);
      else if (index == chars_count - 1)
        Interface::Output(BORDER_TOP_RIGHT_CHAR);
      else
        Interface::Output(BORDER_HORIZONTAL_CHAR);

    Interface::Output();
  }

  void PrintBorderTopWithTitle(int chars_count, string title)
  {
    int title_length = title.length();
    int start_print_index = chars_count / 2 - title_length / 2;

    for (int index = 1; index <= chars_count; index++)
      if (index == 1)
      {
        Interface::Output(BORDER_TOP_LEFT_CHAR);
      }
      else if (index == chars_count)
      {
        Interface::Output(BORDER_TOP_RIGHT_CHAR);
      }
      else if (index == start_print_index)
      {
        Interface::Output(" " + title + " ");
        index += title_length + 1;
      }
      else
      {
        Interface::Output(BORDER_HORIZONTAL_CHAR);
      }

    Interface::Output();
  }

  void PrintBorderBottom(int count)
  {
    for (int index = 0; index < count; index++)
      if (index == 0)
        Interface::Output(BORDER_BOTTOM_LEFT_CHAR);
      else if (index == count - 1)
        Interface::Output(BORDER_BOTTOM_RIGHT_CHAR);
      else
        Interface::Output(BORDER_HORIZONTAL_CHAR);

    Interface::Output();
  }

  unsigned int CalcSpacesCount(int windows_size)
  {
    return Interface::Terminal::GetWidth() / 2 - windows_size / 2;
  }
}
