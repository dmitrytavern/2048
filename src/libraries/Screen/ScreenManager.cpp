#include <iostream>
#include <functional>
#include <csignal>
#include "Screen/Screen.h"
#include "Screen/ScreenManager.h"

using namespace std;

std::function<void(int)> windows_resize_handler;

void signal_handler(int signal) { windows_resize_handler(signal); }

ScreenManager::ScreenManager()
{
  windows_resize_handler = [&](int signal)
  {
    this->WindowsResizeHandler();
  };

  signal(SIGWINCH, signal_handler);

  this->current_screen_exists = false;
  this->ui_exit = false;
}

void ScreenManager::Set(Screen *screen)
{
  this->current_screen = screen;
  this->current_screen_exists = true;
}

void ScreenManager::Run()
{
  // Hide teminal pointer
  printf("\33[?25l");

  while (!this->ui_exit)
    if (this->current_screen_exists)
    {
      system("clear");

      this->current_screen->RunUI();
      this->current_screen->RunAction();
    }

  // Show teminal pointer
  printf("\33[?25h");
}

void ScreenManager::Exit()
{
  this->ui_exit = true;
}

bool ScreenManager::ExistsActiveScreen()
{
  return this->current_screen_exists;
}

Screen *ScreenManager::GetActiveScreen()
{
  if (this->current_screen_exists)
    return this->current_screen;
  exit(1);
}

void ScreenManager::WindowsResizeHandler()
{
  if (this->ExistsActiveScreen())
  {
    system("clear");
    this->GetActiveScreen()->RunUI();
  }
}
