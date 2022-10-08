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
#include "./src/GameController.cpp"
#include "./src/Menu.cpp"

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
  ui_game = new GameUI;
  ui_menu = new MenuUI;
  ui_screen = new ScreenUI;

  ui_screen->AddScreen("main", &UIOutputMainScreen);
  ui_screen->AddScreen("game", &UIOutputGameScreen);
  ui_screen->AddScreen("game_over", &UIOutputGameOverScreen);

  InitMainMenu();
  InitGameMenu();
  InitGameOverMenu();

  ui_screen->SetScreen("main");
  ui_screen->Output();

  std::cout << "Exiting..." << std::endl;
}

void UIOutputMainScreen()
{
  system("clear");

  ui_menu->SetMenu("main");

  ui->Output("2048 Game");
  ui_menu->Output();
  ui_menu->Activate();
}

void UIOutputGameScreen()
{
  system("clear");

  ui_menu->SetMenu("game");

  ui->Output("2048 Game Session");
  ui_game->OutputMatrix();
  ui_menu->Output();
  ui_menu->Activate();

  if (!game.ExistsMove())
    ui_screen->SetScreen("game_over");
}

void UIOutputGameOverScreen()
{
  system("clear");

  ui_menu->SetMenu("game_over");

  ui->Output("2048 Game Over");
  ui_game->OutputMatrix();
  ui_menu->Output();
  ui_menu->Activate();
}

void UIScreenExit()
{
  ui_screen->Exit();
}
