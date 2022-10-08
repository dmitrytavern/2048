#include <iostream>
#include <iomanip>
#include <functional>
#include <conio.h>
#include "main.h"
#include "menus.h"
#include "./menus.cpp"
#include "./src/ui/UI.cpp"
#include "./src/ui/GameUI.cpp"
#include "./src/ui/MenuUI.cpp"
#include "./src/ui/ScreenUI.cpp"
#include "./src/GameMatrix.cpp"
#include "./src/GameMatrixActions.cpp"
#include "./src/Menu.cpp"

UI *ui;
GameUI *ui_game;
MenuUI *ui_menu;
ScreenUI *ui_screen;
GameMatrix *matrix;
GameMatrixActions *controller;
Menu *ui_menu_main;
Menu *ui_menu_game;
Menu *ui_menu_game_over;

int main()
{
  srand(time(0));
  setlocale(LC_ALL, "");

  ui = new UI;
  ui_game = new GameUI;
  ui_menu = new MenuUI;
  ui_screen = new ScreenUI;

  ui_screen->AddScreen("main");
  ui_screen->AddScreen("game");
  ui_screen->AddScreen("game_over");
  ui_screen->SetScreen("main");

  InitMainMenu();
  InitGameMenu();
  InitGameOverMenu();

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

  ui_menu->SetMenu(*ui_menu_main);

  ui->Output("2048 Game");
  ui_menu->OutputMenu();
  ui_menu->ActivateMenu();
}

void UIOutputGameScreen()
{
  system("clear");

  ui_menu->SetMenu(*ui_menu_game);

  ui->Output("2048 Game Session");
  ui_game->OutputMatrix();
  ui_menu->OutputMenu();
  ui_menu->ActivateMenu();
}

void UIOutputGameOverScreen()
{
  system("clear");

  ui_menu->SetMenu(*ui_menu_game_over);

  ui->Output("2048 Game Over");
  ui_game->OutputMatrix();
  ui_menu->OutputMenu();
  ui_menu->ActivateMenu();
}
