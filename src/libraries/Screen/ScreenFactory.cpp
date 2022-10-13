#include <iostream>
#include <iomanip>
#include <string>
#include "UI/UI.h"
#include "Screen/Screen.h"
#include "Screen/ScreenFactory.h"

vector<Screen *> ScreenFactory::screens = {};

void ScreenFactory::AddScreen(Screen *screen)
{
  if (ScreenFactory::ExistsScreen(screen->GetName()))
  {
    cout << "Error: screen " << screen->GetName() << " already exists" << endl;
    exit(1);
  }

  ScreenFactory::screens.push_back(screen);
}

Screen *ScreenFactory::GetScreen(string screen)
{
  for (int index = 0; index < ScreenFactory::screens.size(); index++)
    if (ScreenFactory::screens[index]->GetName() == screen)
      return ScreenFactory::screens[index];
  cout << "Error: screen not found" << endl;
  exit(1);
}

bool ScreenFactory::ExistsScreen(string menu)
{
  for (int index = 0; index < ScreenFactory::screens.size(); index++)
    if (ScreenFactory::screens[index]->GetName() == menu)
      return true;
  return false;
}
