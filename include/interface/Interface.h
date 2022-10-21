#pragma once
#include <iostream>

namespace Interface
{
  void Print();
  void Print(std::string message);
  void PrintSpaces(int count);
  std::string PaintText(int color, std::string text);
  void HideCursor();
  void ShowCursor();
}
