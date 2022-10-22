#include "interface/Interface.h"
#include "interface/TerminalInterface.h"
#include "libraries/Screen/ScreenStore.h"
#include "libraries/Screen/ScreenManager.h"
#include "screens/MainScreen.h"
#include "screens/GameScreen.h"

int main()
{
  srand(time(0));
  setlocale(LC_ALL, "");

  Interface::HideCursor();
  Interface::Terminal::ActivateResizeListener();

  /**
   * Init application screens
   */
  ScreenStore app_screen_store;

  MainScreen app_main_screen;
  app_screen_store.AddScreen(&app_main_screen);

  GameScreen app_game_screen;
  app_screen_store.AddScreen(&app_game_screen);

  /**
   * Start application
   */
  ScreenManager app_screen_manager(&app_screen_store);
  app_screen_manager.Set(&app_main_screen);
  app_screen_manager.Run();

  Interface::Print("Exiting...");
  Interface::ShowCursor();
}
