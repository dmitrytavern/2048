#include <iostream>
#include "../include/GameMatrix.h"

GameMatrix::GameMatrix(unsigned int size)
{
  this->size = size;
  this->matrix = new unsigned int *[size];

  for (int row = 0; row < size; row++)
  {
    matrix[row] = new unsigned int[size];
    for (int column = 0; column < size; column++)
      matrix[row][column] = 0;
  }
}

unsigned int **GameMatrix::GetMatrix()
{
  return this->matrix;
}

unsigned int GameMatrix::GetMatrixSize()
{
  return this->size;
}

unsigned int GameMatrix::GetEmptyCellCount()
{
  int count = 0;

  for (int row = 0; row < this->size; row++)
    for (int column = 0; column < this->size; column++)
      if (matrix[row][column] == 0)
        count++;

  return count;
}
