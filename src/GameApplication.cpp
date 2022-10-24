#include "global.h"
#include "interface/Interface.h"
#include "interface/TerminalInterface.h"
#include "libraries/Screen/ScreenStore.h"
#include "libraries/Screen/ScreenManager.h"
#include "screens/MainScreen.h"
#include "screens/GameScreen.h"
#include "screens/ExitScreen.h"

int main()
{
  srand(time(0));
  setlocale(LC_ALL, "");

  Interface::Terminal::SetTerminalSize(1000, 800);
  Interface::Terminal::DisableTerminalScrollbar();
  Interface::Terminal::ActivateResizeListener();
  Interface::HideCursor();

  /**
   * Init application screens
   */
  ScreenStore app_screen_store;

  MainScreen app_main_screen;
  app_screen_store.AddScreen(&app_main_screen);

  GameScreen app_game_screen(SCREEN_GAME_NAME);
  app_screen_store.AddScreen(&app_game_screen);

  ExitScreen app_exit_screen(SCREEN_EXIT_NAME);
  app_screen_store.AddScreen(&app_exit_screen);

  /**
   * Start application
   */
  ScreenManager app_screen_manager(&app_screen_store);
  app_screen_manager.Set(&app_main_screen);
  app_screen_manager.Run();

  Interface::Terminal::Clear();
  Interface::ShowCursor();
}
