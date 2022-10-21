#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>

namespace Interface::Terminal
{
  unsigned int GetTerminalWidth()
  {
    struct winsize window;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
    return window.ws_col;
  }

  unsigned int GetTerminalHeight()
  {
    struct winsize window;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
    return window.ws_row;
  }
}
