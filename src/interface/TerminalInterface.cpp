#include <iostream>
#ifdef __linux__ 
  #include <sys/ioctl.h>
  #include <unistd.h>
#elif _WIN32
  #include <windows.h>
#else
  exit(1);
#endif

namespace Interface::Terminal
{
  unsigned int GetTerminalWidth()
  {
    #ifdef __linux__
      struct winsize window;
      ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
      return window.ws_col;
    #elif _WIN32
      CONSOLE_SCREEN_BUFFER_INFO csbi;

      GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

      return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    #else
      exit(1);
    #endif
  }

  unsigned int GetTerminalHeight()
  {
    #ifdef __linux__
      struct winsize window;
      ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
      return window.ws_row;
    #elif _WIN32
      CONSOLE_SCREEN_BUFFER_INFO csbi;
      
      GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

      return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    #else
      exit(1);
    #endif
  }
}
