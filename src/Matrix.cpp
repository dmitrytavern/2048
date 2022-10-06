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
    {
      int color = 0;

      switch (this->matrix[row][column])
      {
      case 2:
        color = 31;
        break;
      case 4:
        color = 32;
        break;
      case 8:
        color = 33;
        break;
      case 16:
        color = 34;
        break;
      case 32:
        color = 35;
        break;
      case 64:
        color = 36;
        break;
      case 128:
        color = 37;
        break;
      case 256:
        color = 90;
        break;
      case 512:
        color = 91;
        break;
      case 1024:
        color = 92;
        break;
      case 2048:
        color = 92;
        break;
      default:
        break;
      }

      std::cout << "\t\033[1;" << color << "m" << this->matrix[row][column] << "\033[0m";
    }

    std::cout
        << std::endl;

    if (row != this->size - 1)
      std::cout << std::endl;
  }
}
