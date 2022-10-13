#include <iostream>
#include <functional>

#include "../include/Game/GameController.h"
#include "../include/Menu/Menu.h"
#include "../include/Menu/MenuFactory.h"

#include "../include/UI/UI.h"
#include "../include/Game/GameUI.h"
#include "../include/Menu/MenuUI.h"

#include "../include/Screen/Screen.h"
#include "../include/Screen/ScreenFactory.h"
#include "../include/Screen/ScreenManager.h"

#define MAIN_NAME "main"
#define GAME_NAME "game"
#define GAME_OVER_NAME "game_over"

using namespace std;

enum Triggers
{
  MAIN_MENU_START_GAME_KEY = 97,
  MAIN_MENU_CLOSE_GAME_KEY = 101,

  GAME_MENU_SWIPE_UP_KEY = 119,
  GAME_MENU_SWIPE_LEFT_KEY = 97,
  GAME_MENU_SWIPE_DOWN_KEY = 115,
  GAME_MENU_SWIPE_RIGHT_KEY = 100,
  GAME_MENU_EXIT_KEY = 101,

  GAME_OVER_MENU_START_GAME_KEY = 97,
  GAME_OVER_MENU_EXIT_KEY = 101,
};

void StartGame();
void UIMainScreen();
void UIGameScreen();
void UIGameOverScreen();
void MainScreenAction();
void GameScreenAction();
void GameOverScreenAction();
void UIScreenExit();

GameController game;
ScreenManager app_screen_manager;

int main()
{
  srand(time(0));
  setlocale(LC_ALL, "");

  /**
   * Init application screens
   */
  Screen *main_screen = ScreenFactory::CreateScreen(MAIN_NAME);
  main_screen->SetUIFunction(&UIMainScreen);
  main_screen->SetActionFunction(&MainScreenAction);

  Screen *game_screen = ScreenFactory::CreateScreen(GAME_NAME);
  game_screen->SetUIFunction(&UIGameScreen);
  game_screen->SetActionFunction(&GameScreenAction);

  Screen *game_over_screen = ScreenFactory::CreateScreen(GAME_OVER_NAME);
  game_over_screen->SetUIFunction(&UIGameOverScreen);
  game_over_screen->SetActionFunction(&GameOverScreenAction);

  /**
   * Init application menus
   */
  function<void()> ExitFromGame = [&]() -> void
  {
    app_screen_manager.Set(ScreenFactory::GetScreen(MAIN_NAME));
  };

  Menu *main_menu = MenuFactory::CreateMenu(MAIN_NAME);
  main_menu->SetTitle("Main");
  main_menu->AddAction(MAIN_MENU_START_GAME_KEY, "a - start game", &StartGame);
  main_menu->AddAction(MAIN_MENU_CLOSE_GAME_KEY, "e - close game", &UIScreenExit);

  Menu *game_menu = MenuFactory::CreateMenu(GAME_NAME);
  game_menu->SetTitle("Control");
  game_menu->AddAction(GAME_MENU_SWIPE_UP_KEY, "w - swipe to up", bind(&GameController::SwipeUp, &game));
  game_menu->AddAction(GAME_MENU_SWIPE_LEFT_KEY, "a - swipe to left", bind(&GameController::SwipeLeft, &game));
  game_menu->AddAction(GAME_MENU_SWIPE_DOWN_KEY, "s - swipe to down", bind(&GameController::SwipeDown, &game));
  game_menu->AddAction(GAME_MENU_SWIPE_RIGHT_KEY, "d - swipe to right", bind(&GameController::SwipeRight, &game));
  game_menu->AddAction(GAME_MENU_EXIT_KEY, "e - exit", ExitFromGame);

  Menu *game_over_menu = MenuFactory::CreateMenu(GAME_OVER_NAME);
  game_over_menu->SetTitle("Game Over");
  game_over_menu->AddAction(GAME_OVER_MENU_START_GAME_KEY, "a - new game", &StartGame);
  game_over_menu->AddAction(GAME_OVER_MENU_EXIT_KEY, "e - close game", &UIScreenExit);

  /**
   * Start application
   */
  app_screen_manager.Set(ScreenFactory::GetScreen(MAIN_NAME));
  app_screen_manager.Run();

  UI::Print("Exiting...");
}

void StartGame()
{
  game.Start();

  app_screen_manager.Set(ScreenFactory::GetScreen(GAME_NAME));
}

void UIMainScreen()
{
  Menu *screen_menu = MenuFactory::GetMenu(MAIN_NAME);

  UI::PrintVerticalAlign(6);
  UI::PrintCenter("━━━━ 2048 Game Menu ━━━━", 24);
  UI::Print("");

  MenuUI::PrintMenu(screen_menu);
}

void MainScreenAction()
{
  Menu *screen_menu = MenuFactory::GetMenu(MAIN_NAME);
  MenuUI::ActivateMenu(screen_menu);
}

void UIGameScreen()
{
  Menu *screen_menu = MenuFactory::GetMenu(GAME_NAME);
  GameMatrix *matrix = game.GetMatrix();

  UI::PrintVerticalAlign(4 * 3 + 2 + 1 + 7);
  UI::PrintCenter("━━━━ 2048 Game Session ━━━━", 28);

  GameUI::OutputMatrix(matrix);

  MenuUI::PrintMenu(screen_menu);
}

void GameScreenAction()
{
  Menu *screen_menu = MenuFactory::GetMenu(GAME_NAME);
  MenuUI::ActivateMenu(screen_menu);

  if (!game.ExistsMove())
    app_screen_manager.Set(ScreenFactory::GetScreen(GAME_OVER_NAME));
}

void UIGameOverScreen()
{
  Menu *screen_menu = MenuFactory::GetMenu(GAME_OVER_NAME);
  GameMatrix *matrix = game.GetMatrix();

  UI::PrintVerticalAlign(4 * 3 + 2 + 1 + 4);
  UI::PrintCenter("━━━━ 2048 Game Over ━━━━", 24);

  GameUI::OutputMatrix(matrix);

  MenuUI::PrintMenu(screen_menu);
}

void GameOverScreenAction()
{
  Menu *screen_menu = MenuFactory::GetMenu(GAME_OVER_NAME);
  MenuUI::ActivateMenu(screen_menu);
}

void UIScreenExit()
{
  app_screen_manager.Exit();
}
