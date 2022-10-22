#include <string>
#include "interface/Interface.h"

using namespace std;

namespace Interface
{
  void Print()
  {
    cout << endl;
  }

  void Print(string message)
  {
    cout << message << endl;
  }

  void PrintSpaces(int spaces_count)
  {
    string spaces;
    for (int i = 0; i < spaces_count; i++)
        spaces += " ";
    cout << spaces;
  }

  string PaintText(int color, string message)
  {
#ifdef __linux__
    return "\033[38:5:" + to_string(color) + "m" + message + "\033[0m";
#else
    return "\x1B[" + to_string(color) + "m" + message + "\033[0m";
#endif
  }

  void HideCursor()
  {
    printf("\33[?25l");
  }

  void ShowCursor()
  {
    printf("\33[?25h");
  }
}
