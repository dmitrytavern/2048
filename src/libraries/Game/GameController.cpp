#include <iostream>
#include <string>

#include "libraries/Game/GameController.h"

GameController::GameController()
{
  this->exists_matrix = false;
}

void GameController::Start()
{
  this->matrix = new GameMatrix(4);
  this->exists_move = true;
  this->exists_matrix = true;
  this->Next();
}

void GameController::SwipeUp()
{
  this->matrix->SwipeUp();
  this->Next();
}

void GameController::SwipeLeft()
{
  this->matrix->SwipeLeft();
  this->Next();
}

void GameController::SwipeDown()
{
  this->matrix->SwipeDown();
  this->Next();
}

void GameController::SwipeRight()
{
  this->matrix->SwipeRight();
  this->Next();
}

bool GameController::ExistsMove()
{
  return this->exists_move;
}

bool GameController::ExistsMatrix()
{
  return this->exists_matrix;
}

GameMatrix *GameController::GetMatrix()
{
  return this->matrix;
}

void GameController::Next()
{
  this->matrix->FillRandomCell();
  if (matrix->GetEmptyCellCount() == 0)
    this->exists_move = false;
}
