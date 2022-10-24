#pragma once
#include <iostream>

namespace Interface
{
  static std::string output;

  void Print();
  void Output();
  void Output(std::string message);
  void OutputSpaces(int count);
  std::string PaintText(int color, std::string text);
  void HideCursor();
  void ShowCursor();
}
