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
#ifdef __linux__
    int c, d, e;

    c = getch();
    if (c != 27)
      return c;

    d = getch();
    if (d != 91)
      return d;

    e = getch();

    if (e == 65)
      return KEY_UP;
    if (e == 66)
      return KEY_DOWN;
    if (e == 67)
      return KEY_RIGHT;
    if (e == 68)
      return KEY_LEFT;
    return e;
#else
    int c = getch();
    if (c != 224)
      return c;
    return getch();
#endif
  }

  bool GetComfirm()
  {
    while (true)
    {
      int input = getch();

      switch (input)
      {
      case CHAR_Y:
      case CHAR_Y_UPPER:
      case CHAR_1:
      case KEY_ENTER:
        return true;

      case CHAR_N:
      case CHAR_N_UPPER:
      case CHAR_0:
      case KEY_ESC:
        return false;
      }
    }
  }
}
