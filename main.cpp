#include <iostream>
#include <iomanip>
#include <functional>
#include <conio.h>
#include "./src/GameMatrix.cpp"
#include "./src/GameMatrixActions.cpp"
#include "./src/Menu.cpp"
#include "./src/ui/GameUI.cpp"
#include "./src/ui/MenuUI.cpp"
#include "./src/ui/ScreenUI.cpp"

#define KEY_UP 119
#define KEY_LEFT 97
#define KEY_DOWN 115
#define KEY_RIGHT 100
#define KEY_EXIT 101

GameUI *ui_game;
MenuUI *ui_menu;
ScreenUI *ui_screen;
GameMatrix *matrix;
GameMatrixActions *controller;
Menu *ui_menu_main;
Menu *ui_menu_game;
Menu *ui_menu_game_over;

void InitGame();
void UIOutputMainScreen();
void UIOutputGameScreen();
void UIOutputGameOverScreen();

int main()
{
  srand(time(0));
  setlocale(LC_ALL, "");

  ui_game = new GameUI;
  ui_menu = new MenuUI;
  ui_screen = new ScreenUI;

  ui_screen->AddScreen("main");
  ui_screen->AddScreen("game");
  ui_screen->AddScreen("game_over");

  std::function<void()> ActionSwipeUp = [&]() -> void
  {
    controller->SwipeUp();
    controller->FillRandomCell();
    if (matrix->GetEmptyCellCount() == 0)
      ui_screen->SetScreen("game_over");
  };

  std::function<void()> ActionSwipeLeft = [&]() -> void
  {
    controller->SwipeLeft();
    controller->FillRandomCell();
    if (matrix->GetEmptyCellCount() == 0)
      ui_screen->SetScreen("game_over");
  };

  std::function<void()> ActionSwipeDown = [&]() -> void
  {
    controller->SwipeDown();
    controller->FillRandomCell();
    if (matrix->GetEmptyCellCount() == 0)
      ui_screen->SetScreen("game_over");
  };

  std::function<void()> ActionSwipeRight = [&]() -> void
  {
    controller->SwipeRight();
    controller->FillRandomCell();
    if (matrix->GetEmptyCellCount() == 0)
      ui_screen->SetScreen("game_over");
  };

  std::function<void()> Exit = [&]() -> void
  {
    exit(0);
  };

  ui_menu_main = new Menu;
  ui_menu_main->AddAction(97, "a - start game", &InitGame);
  ui_menu_main->AddAction(KEY_EXIT, "e - close game", Exit);

  ui_menu_game = new Menu;
  ui_menu_game->AddAction(KEY_UP, "w - swipe to up", ActionSwipeUp);
  ui_menu_game->AddAction(KEY_LEFT, "a - swipe to left", ActionSwipeLeft);
  ui_menu_game->AddAction(KEY_DOWN, "s - swipe to down", ActionSwipeDown);
  ui_menu_game->AddAction(KEY_RIGHT, "d - swipe to right", ActionSwipeRight);
  ui_menu_game->AddAction(KEY_EXIT, "e - exit", [&]() -> void
                          { ui_screen->SetScreen("main"); });

  ui_menu_game_over = new Menu;
  ui_menu_game_over->AddAction(97, "a - new game", &InitGame);
  ui_menu_game_over->AddAction(KEY_EXIT, "e - close game", Exit);

  ui_screen->SetScreen("main");

  while (1)
  {
    std::string screen = ui_screen->GetCurrentScreen();

    if (screen == "main")
      UIOutputMainScreen();

    if (screen == "game")
      UIOutputGameScreen();

    if (screen == "game_over")
      UIOutputGameOverScreen();
  }
}

void InitGame()
{
  matrix = new GameMatrix(4);
  controller = new GameMatrixActions(*matrix);
  controller->FillRandomCell();
  ui_game->SetMatrix(*matrix);
  ui_screen->SetScreen("game");
}

void UIOutputMainScreen()
{
  system("clear");

  ui_game->SetTitle("2048 Game");
  ui_menu->SetMenu(*ui_menu_main);

  ui_game->OutputTitle();
  ui_menu->OutputMenu();
  ui_menu->ActivateMenu();
}

void UIOutputGameScreen()
{
  system("clear");

  ui_game->SetTitle("2048 Game Session");
  ui_menu->SetMenu(*ui_menu_game);

  ui_game->OutputTitle();
  ui_game->OutputMatrix();
  ui_menu->OutputMenu();
  ui_menu->ActivateMenu();
}

void UIOutputGameOverScreen()
{
  system("clear");

  ui_game->SetTitle("2048 Game Over");
  ui_menu->SetMenu(*ui_menu_game_over);

  ui_game->OutputTitle();
  ui_game->OutputMatrix();
  ui_menu->OutputMenu();
  ui_menu->ActivateMenu();
}
