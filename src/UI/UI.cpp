#include <sys/ioctl.h>
#include <unistd.h>
#include <string>
#include "../../include/UI/UI.h"

string UI::BORDER_VERTICAL_CHAR = "│";
string UI::BORDER_HORIZONTAL_CHAR = "─";
string UI::BORDER_TOP_LEFT_CHAR = "┌";
string UI::BORDER_TOP_RIGHT_CHAR = "┐";
string UI::BORDER_BOTTOM_LEFT_CHAR = "└";
string UI::BORDER_BOTTOM_RIGHT_CHAR = "┘";

template <typename T>
void UI::Print(T message)
{
  cout << message << endl;
}

void UI::PrintCenter(string message, int message_length = 0)
{
  unsigned int window_width = UI::GetTerminalWidth();
  unsigned int length = message_length == 0 ? message.length() : message_length;

  UI::PrintSpaces(window_width / 2 - length / 2);

  cout << message << endl;
}

void UI::PrintSpaces(int spaces_count)
{
  for (int i = 0; i < spaces_count; i++)
    cout << " ";
}

void UI::PrintWindowBorderTop(int chars_count)
{
  for (int index = 0; index < chars_count; index++)
    if (index == 0)
      cout << UI::BORDER_TOP_LEFT_CHAR;
    else if (index == chars_count - 1)
      cout << UI::BORDER_TOP_RIGHT_CHAR;
    else
      cout << UI::BORDER_HORIZONTAL_CHAR;
  cout << endl;
}

void UI::PrintWindowBorderTopWithTitle(int chars_count, string title)
{
  int title_length = title.length();
  int start_print_index = chars_count / 2 - title_length / 2;

  for (int index = 1; index <= chars_count; index++)
    if (index == 1)
    {
      cout << UI::BORDER_TOP_LEFT_CHAR;
    }
    else if (index == chars_count)
    {
      cout << UI::BORDER_TOP_RIGHT_CHAR;
    }
    else if (index == start_print_index)
    {
      cout << " " << title << " ";
      index += title_length + 1;
    }
    else
    {
      cout << UI::BORDER_HORIZONTAL_CHAR;
    }
  cout << endl;
}

void UI::PrintWindowBorderBottom(int count)
{
  for (int index = 0; index < count; index++)
    if (index == 0)
      cout << UI::BORDER_BOTTOM_LEFT_CHAR;
    else if (index == count - 1)
      cout << UI::BORDER_BOTTOM_RIGHT_CHAR;
    else
      cout << UI::BORDER_HORIZONTAL_CHAR;
  cout << endl;
}

unsigned int UI::GetTerminalWidth()
{
  struct winsize window;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
  return window.ws_col;
}

unsigned int UI::GetTerminalHeight()
{
  struct winsize window;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
  return window.ws_row;
}
