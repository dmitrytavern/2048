#pragma once

#include "GameMatrix.h"

class GameController
{
private:
  GameMatrix *matrix;
  bool exists_move;
  bool exists_matrix;
  void Next();
  int GenerateMatrixNumber();

public:
  GameController();
  void Start();
  void SwipeUp();
  void SwipeLeft();
  void SwipeDown();
  void SwipeRight();
  bool ExistsMove();
  bool ExistsMatrix();
  GameMatrix *GetMatrix();
};
