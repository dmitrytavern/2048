#include <string>
#include "interface/Interface.h"
#ifdef _WIN32
#include <Windows.h>
#endif

using namespace std;

namespace Interface
{
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

  void HideCursor()
  {
#ifdef __linux__
    printf("\33[?25l");
#else
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(out, &cursorInfo);
#endif
  }

  void ShowCursor()
  {
#ifdef __linux__
    printf("\33[?25h");
#else
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(out, &cursorInfo);
#endif
  }
}
