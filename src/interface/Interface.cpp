#include "../../include/interface/Interface.h"
#include <string>

using namespace std;

namespace Interface
{
std::string output = "";

void Print()
{
  printf("%s", output.c_str());
  output = "";
}

void Output()
{
  output += "\n";
}

void Output(string message)
{
  output += message;
}

void OutputInStart(string message)
{
  output = message + output;
}

void OutputSpaces(int spaces_count)
{
  string spaces;
  for (int i = 0; i < spaces_count; i++)
    spaces += " ";
  Output(spaces);
}

string PaintText(int color, string message)
{
#ifdef __linux__
  return "\033[38:5:" + to_string(color) + "m" + message + "\033[0m";
#else
  return "\x1B[" + to_string(color) + "m" + message + "\033[0m";
#endif
}
} // namespace Interface
