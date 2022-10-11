#include <iostream>
#include <iomanip>
#include <string>
#include "UI/UI.h"
#include "Screen/Screen.h"
#include "Screen/ScreenFactory.h"

vector<Screen> ScreenFactory::screens = {};

Screen *ScreenFactory::CreateScreen(string screen_name)
{
  if (ScreenFactory::ExistsScreen(screen_name))
  {
    cout << "Error: screen " << screen_name << " already exists" << endl;
    exit(1);
  }

  ScreenFactory::screens.push_back(*new Screen(screen_name));

  return &ScreenFactory::screens[ScreenFactory::screens.size() - 1];
}

Screen *ScreenFactory::GetScreen(string screen)
{
  for (int index = 0; index < ScreenFactory::screens.size(); index++)
    if (ScreenFactory::screens[index].GetName() == screen)
      return &ScreenFactory::screens[index];
  cout << "Error: screen not found" << endl;
  exit(1);
}

bool ScreenFactory::ExistsScreen(string menu)
{
  for (int index = 0; index < ScreenFactory::screens.size(); index++)
    if (ScreenFactory::screens[index].GetName() == menu)
      return true;
  return false;
}
