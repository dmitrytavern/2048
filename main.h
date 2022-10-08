#ifndef MAIN_H_
#define MAIN_H_

#include "./include/ui/UI.h"
#include "./include/ui/GameUI.h"
#include "./include/ui/MenuUI.h"
#include "./include/ui/ScreenUI.h"
#include "./include/GameMatrix.h"
#include "./include/GameMatrixActions.h"
#include "./include/Menu.h"

extern UI *ui;
extern GameUI *ui_game;
extern MenuUI *ui_menu;
extern ScreenUI *ui_screen;
extern GameMatrix *matrix;
extern GameMatrixActions *controller;
extern Menu *ui_menu_main;
extern Menu *ui_menu_game;
extern Menu *ui_menu_game_over;

void InitGame();
void UIOutputMainScreen();
void UIOutputGameScreen();
void UIOutputGameOverScreen();

#endif
