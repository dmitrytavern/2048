#include <iostream>
#include <iomanip>
#include <string>
#include "UI/UI.h"
#include "Screen/Screen.h"
#include "Screen/ScreenStore.h"

ScreenStore::ScreenStore()
{
  this->screens = {};
}

void ScreenStore::AddScreen(Screen *screen)
{
  if (this->ExistsScreen(screen->GetName()))
  {
    cout << "Error: screen " << screen->GetName() << " already exists" << endl;
    exit(1);
  }

  this->screens.push_back(screen);
}

Screen *ScreenStore::GetScreen(string screen)
{
  for (int index = 0; index < this->screens.size(); index++)
    if (this->screens[index]->GetName() == screen)
      return this->screens[index];
  cout << "Error: screen not found" << endl;
  exit(1);
}

bool ScreenStore::ExistsScreen(string menu)
{
  for (int index = 0; index < this->screens.size(); index++)
    if (this->screens[index]->GetName() == menu)
      return true;
  return false;
}
