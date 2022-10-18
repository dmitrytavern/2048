#pragma once
#include <iostream>

#define SCREEN_SIGNAL_NULL 0
#define SCREEN_SIGNAL_SET 1
#define SCREEN_SIGNAL_EXIT 2

struct ScreenSignal
{
  int signum;
  std::string payload;
};
