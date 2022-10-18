#include <iostream>
#include <functional>
#include <csignal>
#include "libraries/Screen/Screen.h"
#include "libraries/Screen/ScreenStore.h"
#include "libraries/Screen/ScreenSignal.h"
#include "libraries/Screen/ScreenManager.h"

using namespace std;

std::function<void(int)> windows_resize_handler;

void signal_handler(int signal) { windows_resize_handler(signal); }

ScreenManager::ScreenManager(ScreenStore *app_screen_store)
{
  windows_resize_handler = [&](int signal)
  {
    this->WindowsResizeHandler();
  };

  signal(SIGWINCH, signal_handler);

  this->app_screen_store = app_screen_store;
  this->current_screen_exists = false;
  this->ui_exit = false;
}

void ScreenManager::Set(Screen *screen)
{
  if (this->current_screen_exists)
    this->current_screen->Terminate();
  this->current_screen = screen;
  this->current_screen_exists = true;
  this->current_screen->SetSignal(0);
  this->current_screen->Initialize();
}

void ScreenManager::Run()
{
  while (!this->ui_exit)
    if (this->current_screen_exists)
    {
      system("clear");

      this->current_screen->Render();

      this->current_screen->Run();

      ScreenSignal signal = this->current_screen->GetSignal();

      this->SendSignal(signal);

      if (signal.signum != 1)
        this->current_screen->SetSignal(0);
    }
    else
    {
      this->ui_exit = true;
      std::cout << "Warning: ScreenManager have not setted screen." << std::endl;
    }
}

void ScreenManager::Exit()
{
  if (this->current_screen_exists)
    this->current_screen->Terminate();
  this->ui_exit = true;
}

bool ScreenManager::ExistsActiveScreen()
{
  return this->current_screen_exists;
}

void ScreenManager::SendSignal(ScreenSignal signal)
{
  switch (signal.signum)
  {
  case SCREEN_SIGNAL_NULL:
    break;
  case SCREEN_SIGNAL_SET:
    this->Set(this->app_screen_store->GetScreen(signal.payload));
    break;
  case SCREEN_SIGNAL_EXIT:
    this->Exit();
    break;
  default:
    cout << "Error: screen signal '" << signal.signum << "' not found" << endl;
    exit(1);
    break;
  }
}

void ScreenManager::WindowsResizeHandler()
{
  if (this->ExistsActiveScreen())
  {
    system("clear");
    if (this->current_screen_exists)
      this->current_screen->Render();
  }
}
