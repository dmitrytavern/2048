#include <iostream>
#include <functional>
#include "Screen/Screen.h"
#include "Screen/ScreenUI.h"

using namespace std;

ScreenUI::ScreenUI()
{
  this->screens = new Screen[0];
  this->screens_length = 0;
  this->current_screen_exists = false;
  this->screen_ui_exit = false;
}

void ScreenUI::AddScreen(string screen, function<void()> screen_function)
{
  if (this->ExistScreen(screen))
  {
    cout << "Error: screen already exists" << endl;
    return;
  }

  this->screens_length++;

  Screen *temp = new Screen[this->screens_length];

  std::copy(this->screens, this->screens + this->screens_length - 1, temp);

  delete[] this->screens;

  this->screens = temp;
  this->screens[this->screens_length - 1] = *new Screen;
  this->screens[this->screens_length - 1].SetName(screen);
  this->screens[this->screens_length - 1].SetFunction(screen_function);
}

void ScreenUI::SetScreen(string screen)
{
  if (!this->ExistScreen(screen))
  {
    cout << "Error: screen not exists" << endl;
    return;
  }

  this->current_screen = this->GetScreenByName(screen);
  this->current_screen_exists = true;
}

bool ScreenUI::ExistScreen(string screen)
{
  for (int index = 0; index < this->screens_length; index++)
    if (this->screens[index].GetName() == screen)
      return true;
  return false;
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

Screen *ScreenUI::GetScreenByName(string screen)
{
  for (int index = 0; index < this->screens_length; index++)
    if (this->screens[index].GetName() == screen)
      return &this->screens[index];
  exit(1);
}
