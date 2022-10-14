#include <sys/ioctl.h>
#include <unistd.h>
#include <string>

#include "libraries/UI/UI.h"

string UI::BORDER_VERTICAL_CHAR = "│";
string UI::BORDER_HORIZONTAL_CHAR = "─";
string UI::BORDER_TOP_LEFT_CHAR = "┌";
string UI::BORDER_TOP_RIGHT_CHAR = "┐";
string UI::BORDER_BOTTOM_LEFT_CHAR = "└";
string UI::BORDER_BOTTOM_RIGHT_CHAR = "┘";

void UI::Print()
{
  cout << endl;
}

void UI::Print(string message)
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

void UI::PrintVerticalAlign(int content_row_count)
{
  unsigned int window_height = UI::GetTerminalHeight();
  unsigned int length = (window_height - content_row_count) / 2;

  for (int i = 0; i < length; i++)
    cout << endl;
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

string UI::PaintText(int color, string message)
{
  return "\033[38:5:" + to_string(color) + "m" + message + "\033[0m";
}

unsigned int UI::CalcSpacesCount(int windows_size)
{
  return UI::GetTerminalWidth() / 2 - windows_size / 2;
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
