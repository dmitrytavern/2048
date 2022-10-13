#include <iostream>
#include <functional>

#include "Screen/ScreenStore.h"
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
  ScreenStore app_screen_store;
  ScreenManager app_screen_manager;

  MainScreen app_main_screen(&app_screen_store, &app_screen_manager);
  app_screen_store.AddScreen(&app_main_screen);

  GameScreen app_game_screen(&app_screen_store, &app_screen_manager);
  app_screen_store.AddScreen(&app_game_screen);

  /**
   * Start application
   */
  app_screen_manager.Set(&app_main_screen);
  app_screen_manager.Run();

  UI::Print("Exiting...");
}
