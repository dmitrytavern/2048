#include <iostream>
#include <functional>
#include <string>
#include "libraries/Screen/Screen.h"
#include "libraries/Screen/ScreenStore.h"
#include "libraries/Screen/ScreenSignal.h"
#include "libraries/Screen/ScreenManager.h"

using namespace std;

ScreenManager *ScreenManager::currect_manager = nullptr;

ScreenManager::ScreenManager(ScreenStore *app_screen_store)
{
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
  {
    ScreenManager::currect_manager = this;

    if (this->current_screen_exists)
    {
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
      std::cout << "Warning: ScreenManager have not setted screen.\n";
    }
  }
}

void ScreenManager::Exit()
{
  if (this->current_screen_exists)
    this->current_screen->Terminate();
  this->ui_exit = true;
}

void ScreenManager::RenderActiveScreen()
{
  if (this->current_screen_exists)
    this->current_screen->Render();
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
    std::cout << "Error: screen signal '" << signal.signum << "' not found\n";
    exit(1);
    break;
  }
}

ScreenManager *ScreenManager::GetCurrectManager()
{
  return ScreenManager::currect_manager;
}
