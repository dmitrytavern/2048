#ifndef UI_H
#define UI_H

#include <iostream>

using namespace std;

class UI
{
public:
  static string BORDER_VERTICAL_CHAR;
  static string BORDER_HORIZONTAL_CHAR;
  static string BORDER_TOP_LEFT_CHAR;
  static string BORDER_TOP_RIGHT_CHAR;
  static string BORDER_BOTTOM_LEFT_CHAR;
  static string BORDER_BOTTOM_RIGHT_CHAR;

  static void Print(string message);
  static void PrintCenter(string message, int message_length);
  static void PrintSpaces(int spaces_count);
  static void PrintWindowBorderTop(int chars_count);
  static void PrintWindowBorderTopWithTitle(int chars_count, string title);
  static void PrintWindowBorderBottom(int chars_count);
  static unsigned int GetTerminalWidth();
  static unsigned int GetTerminalHeight();
};

#endif
