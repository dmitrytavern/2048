#pragma once
#include <iostream>
#include <functional>

namespace Interface::Terminal
{
  void Clear();
  unsigned int GetTerminalWidth();
  unsigned int GetTerminalHeight();
}

namespace Interface::Terminal
{
  static std::function<void(int)> resize_handler;
  static bool resize_handler_exists;

  void SetResizeHandler(std::function<void(int)> handler);
  void ClearResizeHandler();
  void ActivateResizeListener();
  static void CallResizeHandler(int signum);
}
