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

void GameMatrix::SwipeUp()
{
  std::cout << "Hello test" << this->size << std::endl;
  for (int column = 0; column < this->size; column++)
  {
    unsigned int *current_cell, *previous_cell;
    bool exists_compare = false;

    for (int row = 1; row < this->size; row++)
    {
      previous_cell = &this->matrix[row - 1][column];
      current_cell = &this->matrix[row][column];

      if (this->ExistCompareCells(previous_cell, current_cell))
      {
        this->CompareCells(previous_cell, current_cell);
        exists_compare = true;
      }
    }

    if (exists_compare)
      column--;
  }
}

void GameMatrix::SwipeLeft()
{
  for (int row = 0; row < this->size; row++)
  {
    unsigned int *current_cell, *previous_cell;
    bool exists_compare = false;

    for (int column = 1; column < this->size; column++)
    {
      previous_cell = &this->matrix[row][column - 1];
      current_cell = &this->matrix[row][column];

      if (this->ExistCompareCells(previous_cell, current_cell))
      {
        this->CompareCells(previous_cell, current_cell);
        exists_compare = true;
      }
    }

    if (exists_compare)
      row--;
  }
}

void GameMatrix::SwipeDown()
{
  for (int column = 0; column < this->size; column++)
  {
    unsigned int *current_cell, *previous_cell;
    bool exists_compare = false;

    for (int row = this->size - 1; row > 0; row--)
    {
      previous_cell = &this->matrix[row][column];
      current_cell = &this->matrix[row - 1][column];

      if (this->ExistCompareCells(previous_cell, current_cell))
      {
        this->CompareCells(previous_cell, current_cell);
        exists_compare = true;
      }
    }

    if (exists_compare)
      column--;
  }
}

void GameMatrix::SwipeRight()
{
  for (int row = 0; row < this->size; row++)
  {
    unsigned int *current_cell, *previous_cell;
    bool exists_compare = false;

    for (int column = this->size - 1; column > 0; column--)
    {
      previous_cell = &this->matrix[row][column];
      current_cell = &this->matrix[row][column - 1];

      if (this->ExistCompareCells(previous_cell, current_cell))
      {
        this->CompareCells(previous_cell, current_cell);
        exists_compare = true;
      }
    }

    if (exists_compare)
      row--;
  }
}

void GameMatrix::FillRandomCell()
{
  unsigned int empty_cells = this->GetEmptyCellCount();

  if (empty_cells > 0)
  {
    int selected_cell = std::rand() % (empty_cells - 1 + 1) + 1;

    for (int row = 0; row < this->size; row++)
    {
      for (int column = 0; column < this->size; column++)
      {
        if (this->matrix[row][column] == 0)
        {
          if (selected_cell == 1)
          {
            this->matrix[row][column] = 2;
            selected_cell = 0;
          }
          else if (selected_cell > 1)
          {
            selected_cell--;
          }
        }
      }
    }
  }
}

void GameMatrix::CompareCells(unsigned int *previous_cell, unsigned int *current_cell)
{
  if (*previous_cell == 0 && *current_cell != 0)
  {
    *previous_cell = *current_cell;
    *current_cell = 0;
  }

  if ((*previous_cell == *current_cell) && (*previous_cell != 0 && *current_cell != 0))
  {
    *previous_cell = *current_cell * 2;
    *current_cell = 0;
  }
}

bool GameMatrix::ExistCompareCells(unsigned int *previous_cell, unsigned int *current_cell)
{
  if (*previous_cell == 0 && *current_cell != 0)
    return true;

  if ((*previous_cell == *current_cell) && (*previous_cell != 0 && *current_cell != 0))
    return true;

  return false;
}
