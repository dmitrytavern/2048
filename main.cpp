#include <iostream>
#include <conio.h>

#define KEY_UP 119
#define KEY_DOWN 115
#define KEY_LEFT 97
#define KEY_RIGHT 100
#define KEY_EXIT 101

void show_control_menu();

struct Area
{
  int row;
  int column;
  int **matrix;

  Area()
  {
    row = 4;
    column = 4;
    matrix = new int *[row];

    for (int area_row = 0; area_row < row; area_row++)
      matrix[area_row] = new int[column];

    for (int area_row = 0; area_row < row; area_row++)
      for (int area_column = 0; area_column < column; area_column++)
        matrix[area_row][area_column] = 0;

    matrix[1][1] = 2;
    matrix[2][1] = 2;
    matrix[3][1] = 8;
    matrix[1][3] = 2;
  }
};

struct Game
{
  Area area;

  void output()
  {
    for (int area_row = 0; area_row < area.row; area_row++)
    {
      for (int area_column = 0; area_column < area.column; area_column++)
        std::cout << "\t" << area.matrix[area_row][area_column];
      std::cout << std::endl;

      if (area_row != area.row - 1)
        std::cout << std::endl;
    }
  }

  void swipe_up()
  {
    for (int area_column = 0; area_column < area.column; area_column++)
    {
      bool action = false;
      int *currect, *prev;

      prev = &area.matrix[0][area_column];

      for (int area_row = 1; area_row < area.row; area_row++)
      {
        currect = &area.matrix[area_row][area_column];

        _compare_cells(prev, currect, &action);

        prev = currect;
      }

      if (action)
        area_column--;
    }
  }

  void swipe_down()
  {
    for (int area_column = 0; area_column < area.column; area_column++)
    {
      bool action = false;
      int *currect, *prev;

      prev = &area.matrix[area.row - 1][area_column];

      for (int area_row = area.row - 2; area_row >= 0; area_row--)
      {
        currect = &area.matrix[area_row][area_column];

        _compare_cells(prev, currect, &action);

        prev = currect;
      }

      if (action)
        area_column--;
    }
  }

  void swipe_left()
  {
    for (int area_row = 0; area_row < area.row; area_row++)
    {
      bool action = false;
      int *currect, *prev;

      prev = &area.matrix[area_row][0];

      for (int area_column = 1; area_column < area.column; area_column++)
      {
        currect = &area.matrix[area_row][area_column];

        _compare_cells(prev, currect, &action);

        prev = currect;
      }

      if (action)
        area_row--;
    }
  }

  void swipe_right()
  {
    for (int area_row = 0; area_row < area.row; area_row++)
    {
      bool action = false;
      int *currect, *prev;

      prev = &area.matrix[area_row][area.column - 1];

      for (int area_column = area.column - 2; area_column >= 0; area_column--)
      {
        currect = &area.matrix[area_row][area_column];

        _compare_cells(prev, currect, &action);

        prev = currect;
      }

      if (action)
        area_row--;
    }
  }

  void _compare_cells(int *prev_cell, int *curr_cell, bool *exists_action)
  {
    if (*prev_cell == 0 && *curr_cell != 0)
    {
      *prev_cell = *curr_cell;
      *curr_cell = 0;
      *exists_action = true;
    }

    if ((*prev_cell != 0 && *curr_cell != 0) && (*prev_cell == *curr_cell))
    {
      *prev_cell = *curr_cell * 2;
      *curr_cell = 0;
      *exists_action = true;
    }
  }
};

int main()
{
  Game game;

  while (1)
  {
    system("clear");

    std::cout << "Game:" << std::endl;

    game.output();

    show_control_menu();

    switch (getch())
    {
    case KEY_UP:
      game.swipe_up();
      break;

    case KEY_DOWN:
      game.swipe_down();
      break;

    case KEY_LEFT:
      game.swipe_left();
      break;

    case KEY_RIGHT:
      game.swipe_right();
      break;

    case KEY_EXIT:
      std::cout << "Exiting..." << std::endl;
      exit(0);
      break;

    default:
      std::cout << "Char not found. If you want to exit, press 'e'" << std::endl;
    }
  }
}

void show_control_menu()
{
  std::cout << "w - swipe to up" << std::endl;
  std::cout << "a - swipe to left" << std::endl;
  std::cout << "s - swipe to down" << std::endl;
  std::cout << "d - swipe to right" << std::endl;
  std::cout << "e - exit" << std::endl;
}
