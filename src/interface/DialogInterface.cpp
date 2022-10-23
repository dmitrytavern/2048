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
}
