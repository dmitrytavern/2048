#include <iostream>
#include "interface/DialogInterface.h"
#ifdef __linux__
#include <unistd.h>
#include <termios.h>
int getch()
{
  char buf = 0;
  struct termios old = {0};
  if (tcgetattr(0, &old) < 0)
    perror("tcsetattr()");
  old.c_lflag &= ~ICANON;
  old.c_lflag &= ~ECHO;
  old.c_cc[VMIN] = 1;
  old.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &old) < 0)
    perror("tcsetattr ICANON");
  if (read(0, &buf, 1) < 0)
    perror("read()");
  old.c_lflag |= ICANON;
  old.c_lflag |= ECHO;
  if (tcsetattr(0, TCSADRAIN, &old) < 0)
    perror("tcsetattr ~ICANON");
  return (int(buf));
}
#else
#include <conio.h>
#endif

namespace Interface::Dialog
{
  int GetCharCode()
  {
    return getch();
  }

  bool GetComfirm()
  {
    while (true)
    {
      int input = getch();

      if (input == CHAR_Y || input == CHAR_1)
        return true;

      if (input == CHAR_N || input == CHAR_0)
        return false;
    }
  }
}
