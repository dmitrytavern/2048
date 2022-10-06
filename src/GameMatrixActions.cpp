#include <iostream>
#include "../include/GameMatrixActions.h"

GameMatrixActions::GameMatrixActions(GameMatrix &matrix)
{
  this->matrix = &matrix;
}

void GameMatrixActions::SwipeUp()
{
  unsigned int **matrix = this->matrix->GetMatrix();
  unsigned int size = this->matrix->GetMatrixSize();

  for (int column = 0; column < size; column++)
  {
    unsigned int *current_cell, *previous_cell;
    bool exists_compare = false;

    for (int row = 1; row < size; row++)
    {
      previous_cell = &matrix[row - 1][column];
      current_cell = &matrix[row][column];

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

void GameMatrixActions::SwipeDown()
{
  unsigned int **matrix = this->matrix->GetMatrix();
  unsigned int size = this->matrix->GetMatrixSize();

  for (int column = 0; column < size; column++)
  {
    unsigned int *current_cell, *previous_cell;
    bool exists_compare = false;

    for (int row = size - 1; row > 0; row--)
    {
      previous_cell = &matrix[row][column];
      current_cell = &matrix[row - 1][column];

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

void GameMatrixActions::SwipeLeft()
{
  unsigned int **matrix = this->matrix->GetMatrix();
  unsigned int size = this->matrix->GetMatrixSize();

  for (int row = 0; row < size; row++)
  {
    unsigned int *current_cell, *previous_cell;
    bool exists_compare = false;

    for (int column = 1; column < size; column++)
    {
      previous_cell = &matrix[row][column - 1];
      current_cell = &matrix[row][column];

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

void GameMatrixActions::SwipeRight()
{
  unsigned int **matrix = this->matrix->GetMatrix();
  unsigned int size = this->matrix->GetMatrixSize();

  for (int row = 0; row < size; row++)
  {
    unsigned int *current_cell, *previous_cell;
    bool exists_compare = false;

    for (int column = size - 1; column > 0; column--)
    {
      previous_cell = &matrix[row][column];
      current_cell = &matrix[row][column - 1];

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

void GameMatrixActions::FillRandomCell()
{
  unsigned int **matrix = this->matrix->GetMatrix();
  unsigned int size = this->matrix->GetMatrixSize();
  unsigned int empty_cells = this->matrix->GetEmptyCellCount();

  if (empty_cells > 0)
  {
    int selected_cell = std::rand() % (empty_cells - 1 + 1) + 1;

    for (int row = 0; row < size; row++)
    {
      for (int column = 0; column < size; column++)
      {
        if (matrix[row][column] == 0)
        {
          if (selected_cell == 1)
          {
            matrix[row][column] = 2;
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

void GameMatrixActions::CompareCells(unsigned int *previous_cell, unsigned int *current_cell)
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

bool GameMatrixActions::ExistCompareCells(unsigned int *previous_cell, unsigned int *current_cell)
{
  if (*previous_cell == 0 && *current_cell != 0)
    return true;

  if ((*previous_cell == *current_cell) && (*previous_cell != 0 && *current_cell != 0))
    return true;

  return false;
}
