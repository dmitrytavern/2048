#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
private:
  unsigned int size;
  unsigned int **matrix;

public:
  Matrix(unsigned int size);
  unsigned int **GetMatrix();
  unsigned int GetMatrixSize();
  unsigned int GetEmptyCellCount();
  void OutputMatrix();
};

#endif
