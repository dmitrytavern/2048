#pragma once
#include <iostream>

namespace Interface
{
  extern std::string output;

  void Print();
  void Output();
  void Output(std::string message);
  void OutputInStart(std::string message);
  void OutputSpaces(int count);
  std::string PaintText(int color, std::string text);
}
