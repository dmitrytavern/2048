#pragma once
#include <iostream>

namespace Interface::Window
{
#ifdef __linux__
  const std::string BORDER_VERTICAL_CHAR = "│";
  const std::string BORDER_HORIZONTAL_CHAR = "─";
  const std::string BORDER_TOP_LEFT_CHAR = "┌";
  const std::string BORDER_TOP_RIGHT_CHAR = "┐";
  const std::string BORDER_BOTTOM_LEFT_CHAR = "└";
  const std::string BORDER_BOTTOM_RIGHT_CHAR = "┘";
#else
  const std::string BORDER_VERTICAL_CHAR = "|";
  const std::string BORDER_HORIZONTAL_CHAR = "-";
  const std::string BORDER_TOP_LEFT_CHAR = "+";
  const std::string BORDER_TOP_RIGHT_CHAR = "+";
  const std::string BORDER_BOTTOM_LEFT_CHAR = "+";
  const std::string BORDER_BOTTOM_RIGHT_CHAR = "+";
#endif

  void PrintCenter(std::string message);
  void PrintCenter(std::string message, int message_length);
  void PrintVerticalAlign(int count);
  void PrintBorderTop(int chars_count);
  void PrintBorderTopWithTitle(int chars_count, std::string title);
  void PrintBorderBottom(int chars_count);
  unsigned int CalcSpacesCount(int windows_size);
}