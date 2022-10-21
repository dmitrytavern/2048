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
    for (int i = 0; i < spaces_count; i++)
      cout << " ";
  }

  string PaintText(int color, string message)
  {
    return "\033[38:5:" + to_string(color) + "m" + message + "\033[0m";
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
