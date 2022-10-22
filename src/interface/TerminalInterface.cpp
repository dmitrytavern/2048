#include <iostream>
#include <functional>
#ifdef __linux__
#include <sys/ioctl.h>
#include <unistd.h>
#include <csignal>
#else
#include <windows.h>
#endif

namespace Interface::Terminal
{
#ifdef __linux__
  void Clear()
  {
    system("clear");
  }

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
#else
  void Clear()
  {
    system("cls");
  }

  unsigned int GetTerminalWidth()
  {
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
  }

  unsigned int GetTerminalHeight()
  {
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
  }
#endif
}

namespace Interface::Terminal
{
  static std::function<void(int)> resize_handler;
  static bool resize_handler_exists = false;

  void SetResizeHandler(std::function<void(int)> handler)
  {
    resize_handler = handler;
    resize_handler_exists = true;
  }

  void ClearResizeHandler()
  {
    resize_handler = NULL;
    resize_handler_exists = false;
  }

  static void CallResizeHandler(int signum)
  {
    if (resize_handler_exists)
      resize_handler(signum);
  }
#ifdef __linux__
  void ActivateResizeListener()
  {
    signal(SIGWINCH, &CallResizeHandler);
  }
#else
  void ActivateResizeListener()
  {
    std::cout << "Windows don't support hot resizing." << std::endl;
  }
#endif
}