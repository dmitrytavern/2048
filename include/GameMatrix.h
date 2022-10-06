#ifndef GAMEMATRIX_H
#define GAMEMATRIX_H

class GameMatrix
{
private:
  unsigned int size;
  unsigned int **matrix;

public:
  GameMatrix(unsigned int size);
  unsigned int **GetMatrix();
  unsigned int GetMatrixSize();
  unsigned int GetEmptyCellCount();
  void OutputMatrix();
};

#endif
