#include <iostream>
#include <iomanip>
#include <string>
#include "UI/UI.h"
#include "Screen/Screen.h"
#include "Screen/ScreenFactory.h"

vector<Screen> ScreenFactory::screens = {};

void ScreenFactory::AddScreen(string screen_name, function<void()> screen_function)
{
  if (ScreenFactory::ExistsScreen(screen_name))
  {
    cout << "Error: screen " << screen_name << " already exists" << endl;
    exit(1);
  }

  Screen *new_screen = new Screen(screen_name);

  new_screen->SetFunction(screen_function);

  ScreenFactory::screens.push_back(*new_screen);
}

Screen *ScreenFactory::GetScreen(string screen)
{
  for (int index = 0; index < ScreenFactory::screens.size(); index++)
    if (ScreenFactory::screens[index].GetName() == screen)
      return &ScreenFactory::screens[index];
  cout << "Error: menu not found" << endl;
  exit(1);
}

bool ScreenFactory::ExistsScreen(string menu)
{
  for (int index = 0; index < ScreenFactory::screens.size(); index++)
    if (ScreenFactory::screens[index].GetName() == menu)
      return true;
  return false;
}
