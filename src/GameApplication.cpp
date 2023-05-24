#include "../include/global.h"
#include "../include/interface/Interface.h"
#include "../include/interface/TerminalInterface.h"
#include "../include/libraries/Screen/ScreenManager.h"
#include "../include/libraries/Screen/ScreenStore.h"
#include "../include/screens/AboutScreen.h"
#include "../include/screens/ExitScreen.h"
#include "../include/screens/GameScreen.h"
#include "../include/screens/MainScreen.h"

void TerminalResizeHandler(int signum);

int main()
{
  srand(time(0));
  setlocale(LC_ALL, "");

/**
 * Set terminal
 */
#ifdef _WIN32
  Interface::Terminal::SetWindowSize(1000, 800);
  Interface::Terminal::DisableWindowScrollbar();
#endif

#ifdef __linux__
  Interface::Terminal::SetResizeHandler(&TerminalResizeHandler);
  Interface::Terminal::ActivateResizeListener();
#endif
  Interface::Terminal::HideCursor();

  /**
   * Init application screens
   */
  ScreenStore app_screen_store;

  MainScreen app_main_screen;
  app_screen_store.AddScreen(&app_main_screen);

  GameScreen app_game_screen(SCREEN_GAME_NAME); // NOLINT
  app_screen_store.AddScreen(&app_game_screen);

  AboutScreen app_about_screen;
  app_screen_store.AddScreen(&app_about_screen);

  ExitScreen app_exit_screen(SCREEN_EXIT_NAME);
  app_screen_store.AddScreen(&app_exit_screen);

  /**
   * Start application
   */
  ScreenManager app_screen_manager(&app_screen_store);
  app_screen_manager.Set(&app_main_screen);
  app_screen_manager.Run();

  Interface::Terminal::Clear();
  Interface::Terminal::ShowCursor();
}

void TerminalResizeHandler(int signum)
{
  ScreenManager *manager = ScreenManager::GetCurrectManager();
  if (manager)
    manager->RenderActiveScreen();
}
