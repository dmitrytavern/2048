#ifndef UI_H
#define UI_H

#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

using namespace std;

class UI
{
private:
  struct winsize *size;

public:
  UI();
  void Output(string text);
  void OutputCenter(string text, int text_length);
  void OutputSpaces(int count);
  void OutputBorderTop(int count);
  void OutputBorderBottom(int count);
  void UpdateTerminalSize();
  winsize *GetTerminalSize();
};

#endif
