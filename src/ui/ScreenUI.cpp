#include "../../include/ui/ScreenUI.h"

ScreenUI::ScreenUI()
{
  this->screens = new string[0];
  this->screens_length = 0;
}

void ScreenUI::AddScreen(string screen)
{
  if (this->ExistScreen(screen))
  {
    cout << "Error: screen already exists" << endl;
    return;
  }

  this->screens_length++;

  string *temp = new string[this->screens_length];

  std::copy(this->screens, this->screens + this->screens_length - 1, temp);

  delete[] this->screens;

  this->screens = temp;

  this->screens[this->screens_length - 1] = screen;
}

void ScreenUI::SetScreen(string screen)
{
  if (!this->ExistScreen(screen))
  {
    cout << "Error: screen not exists" << endl;
    return;
  }

  this->current_screen = screen;
}

bool ScreenUI::ExistScreen(string screen)
{
  for (int index = 0; index < this->screens_length; index++)
    if (this->screens[index] == screen)
      return true;
  return false;
}

string ScreenUI::GetCurrentScreen()
{
  return this->current_screen;
}
