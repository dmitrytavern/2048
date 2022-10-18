#pragma once
#include "GameMatrix.h"

class GameController
{
private:
  int score;
  GameMatrix *matrix;
  bool exists_move;
  bool exists_matrix;
  void Next();
  int GenerateMatrixNumber();

public:
  GameController();
  int GetScore();
  void Start();
  void SwipeUp();
  void SwipeLeft();
  void SwipeDown();
  void SwipeRight();
  bool ExistsMove();
  bool ExistsMatrix();
  GameMatrix *GetMatrix();
};
