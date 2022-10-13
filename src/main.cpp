#include <iostream>
#include <functional>

#include "Screen/ScreenFactory.h"
#include "Screen/ScreenManager.h"

#include "./screens/MainScreen.h"
#include "./screens/GameScreen.h"

#include "UI/UI.h"

using namespace std;

int main()
{
  srand(time(0));
  setlocale(LC_ALL, "");

  /**
   * Init application screens
   */
  ScreenManager app_screen_manager;

  MainScreen app_main_screen(&app_screen_manager);
  ScreenFactory::AddScreen(&app_main_screen);

  GameScreen app_game_screen(&app_screen_manager);
  ScreenFactory::AddScreen(&app_game_screen);

  /**
   * Start application
   */
  app_screen_manager.Set("main");
  app_screen_manager.Run();

  UI::Print("Exiting...");
}
