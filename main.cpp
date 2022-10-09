#include <iostream>
#include <iomanip>
#include <functional>
#include <conio.h>
#include "main.h"
#include "./src/ui/UI.cpp"
#include "./src/ui/GameUI.cpp"
#include "./src/ui/MenuUI.cpp"
#include "./src/ui/ScreenUI.cpp"
#include "./src/Menu.cpp"
#include "./src/GameMatrix.cpp"
#include "./src/GameController.cpp"

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

UI *ui;
GameUI *ui_game;
MenuUI *ui_menu;
ScreenUI *ui_screen;
GameController game;

int main()
{
  srand(time(0));
  setlocale(LC_ALL, "");

  ui = new UI;
  ui_game = new GameUI(*ui);
  ui_menu = new MenuUI(*ui);
  ui_screen = new ScreenUI(*ui);

  ui_screen->AddScreen(MAIN_NAME, &UIOutputMainScreen);
  ui_screen->AddScreen(GAME_NAME, &UIOutputGameScreen);
  ui_screen->AddScreen(GAME_OVER_NAME, &UIOutputGameOverScreen);

  function<void()> ExitFromGame = [&]() -> void
  {
    ui_screen->SetScreen(MAIN_NAME);
  };

  Menu main_menu;
  main_menu.SetName(MAIN_NAME);
  main_menu.AddAction(MAIN_MENU_START_GAME_KEY, "a - start game", &StartGame);
  main_menu.AddAction(MAIN_MENU_CLOSE_GAME_KEY, "e - close game", &UIScreenExit);
  ui_menu->AddMenu(main_menu);

  Menu game_menu;
  game_menu.SetName(GAME_NAME);
  game_menu.AddAction(GAME_MENU_SWIPE_UP_KEY, "w - swipe to up", bind(&GameController::SwipeUp, &game));
  game_menu.AddAction(GAME_MENU_SWIPE_LEFT_KEY, "a - swipe to left", bind(&GameController::SwipeLeft, &game));
  game_menu.AddAction(GAME_MENU_SWIPE_DOWN_KEY, "s - swipe to down", bind(&GameController::SwipeDown, &game));
  game_menu.AddAction(GAME_MENU_SWIPE_RIGHT_KEY, "d - swipe to right", bind(&GameController::SwipeRight, &game));
  game_menu.AddAction(GAME_MENU_EXIT_KEY, "e - exit", ExitFromGame);
  ui_menu->AddMenu(game_menu);

  Menu game_over_menu;
  game_over_menu.SetName(GAME_OVER_NAME);
  game_over_menu.AddAction(GAME_OVER_MENU_START_GAME_KEY, "a - new game", &StartGame);
  game_over_menu.AddAction(GAME_OVER_MENU_EXIT_KEY, "e - close game", &UIScreenExit);
  ui_menu->AddMenu(game_over_menu);

  ui_screen->SetScreen(MAIN_NAME);
  ui_screen->Output();

  ui->Output("Exiting...");
}

void StartGame()
{
  game.Start();

  ui_game->SetMatrix(*game.GetMatrix());
  ui_screen->SetScreen(GAME_NAME);
}

void UIOutputMainScreen()
{
  system("clear");

  ui_menu->SetMenu(MAIN_NAME);

  ui->UpdateTerminalSize();
  ui->OutputCenter("━━━━ 2048 Game Menu ━━━━", 24);
  ui_menu->Output();
  ui_menu->Activate();
}

void UIOutputGameScreen()
{
  system("clear");

  ui_menu->SetMenu(GAME_NAME);

  ui->UpdateTerminalSize();
  ui->OutputCenter("━━━━ 2048 Game Session ━━━━", 28);
  ui_game->OutputMatrix();
  ui_menu->Output();
  ui_menu->Activate();

  if (!game.ExistsMove())
    ui_screen->SetScreen(GAME_OVER_NAME);
}

void UIOutputGameOverScreen()
{
  system("clear");

  ui_menu->SetMenu(GAME_OVER_NAME);

  ui->UpdateTerminalSize();
  ui->OutputCenter("━━━━ 2048 Game Over ━━━━", 24);
  ui_game->OutputMatrix();
  ui_menu->Output();
  ui_menu->Activate();
}

void UIScreenExit()
{
  ui_screen->Exit();
}
