#ifndef MAIN_H_
#define MAIN_H_

#include "./include/ui/UI.h"
#include "./include/ui/GameUI.h"
#include "./include/ui/MenuUI.h"
#include "./include/ui/ScreenUI.h"
#include "./include/GameMatrix.h"
#include "./include/GameController.h"
#include "./include/Menu.h"

extern UI *ui;
extern GameUI *ui_game;
extern MenuUI *ui_menu;
extern ScreenUI *ui_screen;
extern GameController game;

void UIOutputMainScreen();
void UIOutputGameScreen();
void UIOutputGameOverScreen();

#endif
