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
  this->score = 0;
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
  int number = this->GenerateMatrixNumber();
  this->matrix->FillRandomCell(number);
  this->score += number;
  if (matrix->GetEmptyCellCount() == 0)
    this->exists_move = false;
}

int GameController::GetScore()
{
  return this->score;
}

int GameController::GenerateMatrixNumber()
{
  if (this->score >= 128)
    return (std::rand() % (2 - 1 + 1) + 1) * 2;
  return 2;
}
