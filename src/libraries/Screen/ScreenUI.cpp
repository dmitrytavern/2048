#include <iostream>
#include <functional>
#include "Screen/Screen.h"
#include "Screen/ScreenUI.h"

using namespace std;

ScreenUI::ScreenUI()
{
  this->current_screen_exists = false;
  this->screen_ui_exit = false;
}

void ScreenUI::SetScreen(Screen *screen)
{
  this->current_screen = screen;
  this->current_screen_exists = true;
}

bool ScreenUI::ExistCurrentScreen()
{
  return this->current_screen_exists;
}

string ScreenUI::GetCurrentScreen()
{
  if (this->current_screen_exists)
    return this->current_screen->GetName();
  exit(1);
}

void ScreenUI::Output()
{
  // Hide teminal pointer
  printf("\33[?25l");

  while (!this->screen_ui_exit)
    if (this->current_screen_exists)
    {
      system("clear");

      this->current_screen->Execute();
    }

  // Show teminal pointer
  printf("\33[?25h");
}

void ScreenUI::Exit()
{
  this->screen_ui_exit = true;
}
