#include <iostream>
#include <iomanip>
#include <functional>
#include <csignal>

#include "../include/Game/GameController.h"
#include "../include/Menu/Menu.h"
#include "../include/Menu/MenuFactory.h"

#include "../include/UI/UI.h"
#include "../include/Game/GameUI.h"
#include "../include/Menu/MenuUI.h"

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
void UIOutputMainScreen();
void UIOutputGameScreen();
void UIOutputGameOverScreen();
void UIScreenExit();

GameUI *ui_game;
ScreenManager *screen_manager;
GameController game;

int main()
{
  srand(time(0));
  setlocale(LC_ALL, "");

  ui_game = new GameUI();
  screen_manager = new ScreenManager();

  ScreenFactory::AddScreen(MAIN_NAME, &UIOutputMainScreen);
  ScreenFactory::AddScreen(GAME_NAME, &UIOutputGameScreen);
  ScreenFactory::AddScreen(GAME_OVER_NAME, &UIOutputGameOverScreen);

  function<void()> ExitFromGame = [&]() -> void
  {
    screen_manager->Set(ScreenFactory::GetScreen(MAIN_NAME));
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

  screen_manager->Set(ScreenFactory::GetScreen(MAIN_NAME));
  screen_manager->Run();

  UI::Print("Exiting...");
}

void StartGame()
{
  game.Start();

  ui_game->SetMatrix(*game.GetMatrix());
  screen_manager->Set(ScreenFactory::GetScreen(GAME_NAME));
}

void UIOutputMainScreen()
{
  Menu *screen_menu = MenuFactory::GetMenu(MAIN_NAME);

  UI::PrintVerticalAlign(6);
  UI::PrintCenter("━━━━ 2048 Game Menu ━━━━", 24);
  UI::Print("");

  MenuUI::PrintMenu(screen_menu);
  MenuUI::ActivateMenu(screen_menu);
}

void UIOutputGameScreen()
{
  Menu *screen_menu = MenuFactory::GetMenu(GAME_NAME);

  UI::PrintVerticalAlign(4 * 3 + 2 + 1 + 7);
  UI::PrintCenter("━━━━ 2048 Game Session ━━━━", 28);

  ui_game->OutputMatrix();

  MenuUI::PrintMenu(screen_menu);
  MenuUI::ActivateMenu(screen_menu);

  if (!game.ExistsMove())
    screen_manager->Set(ScreenFactory::GetScreen(GAME_OVER_NAME));
}

void UIOutputGameOverScreen()
{
  Menu *screen_menu = MenuFactory::GetMenu(GAME_OVER_NAME);

  UI::PrintVerticalAlign(4 * 3 + 2 + 1 + 4);
  UI::PrintCenter("━━━━ 2048 Game Over ━━━━", 24);

  ui_game->OutputMatrix();

  MenuUI::PrintMenu(screen_menu);
  MenuUI::ActivateMenu(screen_menu);
}

void UIScreenExit()
{
  screen_manager->Exit();
}
