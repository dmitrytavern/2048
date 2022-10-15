#pragma once
#include <iostream>

using namespace std;

class UI
{
public:
  static const string BORDER_VERTICAL_CHAR;
  static const string BORDER_HORIZONTAL_CHAR;
  static const string BORDER_TOP_LEFT_CHAR;
  static const string BORDER_TOP_RIGHT_CHAR;
  static const string BORDER_BOTTOM_LEFT_CHAR;
  static const string BORDER_BOTTOM_RIGHT_CHAR;

  static void Print();
  static void Print(string message);
  static void PrintCenter(string message, int message_length);
  static void PrintSpaces(int spaces_count);
  static void PrintVerticalAlign(int content_row_count);
  static void PrintWindowBorderTop(int chars_count);
  static void PrintWindowBorderTopWithTitle(int chars_count, string title);
  static void PrintWindowBorderBottom(int chars_count);
  static string PaintText(int color, string text);
  static unsigned int GetTerminalWidth();
  static unsigned int GetTerminalHeight();
  static unsigned int CalcSpacesCount(int windows_size);
};
