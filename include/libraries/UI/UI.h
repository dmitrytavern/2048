#pragma once
#include <iostream>

class UI
{
public:
  static const std::string BORDER_VERTICAL_CHAR;
  static const std::string BORDER_HORIZONTAL_CHAR;
  static const std::string BORDER_TOP_LEFT_CHAR;
  static const std::string BORDER_TOP_RIGHT_CHAR;
  static const std::string BORDER_BOTTOM_LEFT_CHAR;
  static const std::string BORDER_BOTTOM_RIGHT_CHAR;

  static void Print();
  static void Print(std::string message);
  static void PrintCenter(std::string message);
  static void PrintCenter(std::string message, int message_length);
  static void PrintSpaces(int spaces_count);
  static void PrintVerticalAlign(int content_row_count);
  static void PrintWindowBorderTop(int chars_count);
  static void PrintWindowBorderTopWithTitle(int chars_count, std::string title);
  static void PrintWindowBorderBottom(int chars_count);
  static std::string PaintText(int color, std::string text);
  static unsigned int GetTerminalWidth();
  static unsigned int GetTerminalHeight();
  static unsigned int CalcSpacesCount(int windows_size);
  static void HideCursor();
  static void ShowCursor();
};
