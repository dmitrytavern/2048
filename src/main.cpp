#include <iostream>
#include <iomanip>
#include <functional>
#include <csignal>

#include "../include/Game/GameController.h"
#include "../include/Menu/Menu.h"

#include "../include/UI/UI.h"
#include "../include/Game/GameUI.h"
#include "../include/Menu/MenuUI.h"
#include "../include/Screen/ScreenUI.h"

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
MenuUI *ui_menu;
ScreenUI *ui_screen;
GameController game;

int main()
{
  srand(time(0));
  setlocale(LC_ALL, "");

  ui_game = new GameUI();
  ui_menu = new MenuUI();
  ui_screen = new ScreenUI();

  ui_screen->AddScreen(MAIN_NAME, &UIOutputMainScreen);
  ui_screen->AddScreen(GAME_NAME, &UIOutputGameScreen);
  ui_screen->AddScreen(GAME_OVER_NAME, &UIOutputGameOverScreen);

  function<void()> ExitFromGame = [&]() -> void
  {
    ui_screen->SetScreen(MAIN_NAME);
  };

  Menu main_menu;
  main_menu.SetName(MAIN_NAME);
  main_menu.SetTitle("Main");
  main_menu.AddAction(MAIN_MENU_START_GAME_KEY, "a - start game", &StartGame);
  main_menu.AddAction(MAIN_MENU_CLOSE_GAME_KEY, "e - close game", &UIScreenExit);
  ui_menu->AddMenu(main_menu);

  Menu game_menu;
  game_menu.SetName(GAME_NAME);
  game_menu.SetTitle("Control");
  game_menu.AddAction(GAME_MENU_SWIPE_UP_KEY, "w - swipe to up", bind(&GameController::SwipeUp, &game));
  game_menu.AddAction(GAME_MENU_SWIPE_LEFT_KEY, "a - swipe to left", bind(&GameController::SwipeLeft, &game));
  game_menu.AddAction(GAME_MENU_SWIPE_DOWN_KEY, "s - swipe to down", bind(&GameController::SwipeDown, &game));
  game_menu.AddAction(GAME_MENU_SWIPE_RIGHT_KEY, "d - swipe to right", bind(&GameController::SwipeRight, &game));
  game_menu.AddAction(GAME_MENU_EXIT_KEY, "e - exit", ExitFromGame);
  ui_menu->AddMenu(game_menu);

  Menu game_over_menu;
  game_over_menu.SetName(GAME_OVER_NAME);
  game_over_menu.SetTitle("Game Over");
  game_over_menu.AddAction(GAME_OVER_MENU_START_GAME_KEY, "a - new game", &StartGame);
  game_over_menu.AddAction(GAME_OVER_MENU_EXIT_KEY, "e - close game", &UIScreenExit);
  ui_menu->AddMenu(game_over_menu);

  ui_screen->SetScreen(MAIN_NAME);
  ui_screen->Output();

  UI::Print("Exiting...");
}

void StartGame()
{
  game.Start();

  ui_game->SetMatrix(*game.GetMatrix());
  ui_screen->SetScreen(GAME_NAME);
}

void UIOutputMainScreen()
{
  ui_menu->SetMenu(MAIN_NAME);

  UI::PrintVerticalAlign(6);
  UI::PrintCenter("━━━━ 2048 Game Menu ━━━━", 24);
  UI::Print("");

  ui_menu->Output();
  ui_menu->Activate();
}

void UIOutputGameScreen()
{
  ui_menu->SetMenu(GAME_NAME);

  UI::PrintVerticalAlign(4 * 3 + 2 + 1 + 7);
  UI::PrintCenter("━━━━ 2048 Game Session ━━━━", 28);

  ui_game->OutputMatrix();
  ui_menu->Output();
  ui_menu->Activate();

  if (!game.ExistsMove())
    ui_screen->SetScreen(GAME_OVER_NAME);
}

void UIOutputGameOverScreen()
{
  ui_menu->SetMenu(GAME_OVER_NAME);

  UI::PrintVerticalAlign(4 * 3 + 2 + 1 + 4);
  UI::PrintCenter("━━━━ 2048 Game Over ━━━━", 24);

  ui_game->OutputMatrix();
  ui_menu->Output();
  ui_menu->Activate();
}

void UIScreenExit()
{
  ui_screen->Exit();
}
