#include <iostream>
#include "../include/Matrix.h"

Matrix::Matrix(unsigned int size)
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

unsigned int **Matrix::GetMatrix()
{
  return this->matrix;
}

unsigned int Matrix::GetMatrixSize()
{
  return this->size;
}

unsigned int Matrix::GetEmptyCellCount()
{
  int count = 0;

  for (int row = 0; row < this->size; row++)
    for (int column = 0; column < this->size; column++)
      if (matrix[row][column] == 0)
        count++;

  return count;
}

void Matrix::OutputMatrix()
{
  for (int row = 0; row < this->size; row++)
  {
    for (int column = 0; column < this->size; column++)
      std::cout << "\t" << this->matrix[row][column];
    std::cout << std::endl;
    if (row != this->size - 1)
      std::cout << std::endl;
  }
}
