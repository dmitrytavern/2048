#include <iostream>
#include "interface/DialogInterface.h"
#ifdef __linux__
#include <coniolinux.h>
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
