//Name: Louis Gomez
//Class: Object Oriented Programming
//Class Project

#include "matrix.hpp"
#include <iostream>
#include <fstream>

using namespace std;

//constructor - add error handlin gi file does not exist
Matrix::Matrix(unsigned int r, unsigned int c, string file_name)
{
  ifstream input_file;
  input_file.open(file_name);

  if(input_file.is_open())
  {
    N_row = r;
    N_col = c;

    //int num_of_data_points = r * c;
    //mat.resize(r);
    for (unsigned i = 0; i < N_row; i++)
    {
      for(unsigned j = 0; j < N_col; j++)
      {
        input_file >> mat[i][j];
        input_file.get();
      }
      //while(getline(input_file, )
    }
  }
}

Matrix::Matrix(unsigned int r, unsigned int c, int m): N_row(r), N_col(c)
{
  for (unsigned i = 0; i < N_row; i++)
  {
    for(unsigned j = 0; j < N_col; j++)
    {
      mat[i][j] = m;
    }
    //while(getline(input_file, )
  }
}

//copy constructor
Matrix::Matrix(const Matrix& val)
{
  mat = val.mat;
  N_row = val.N_row;
  N_col = val.N_col;
}

//Matrix multiplication - add error handling for mismatch dimension
Matrix Matrix::operator* (const Matrix& val)
{
  unsigned int new_row = N_row;
  unsigned int new_col = val.get_column;

  Matrix result(new_row, new_col, 1);
  //add caluclation here
  for (unsigned i = 0; i < N_row; i++)
  {
    for(unsigned j = 0; j < val.get_column; j++)
    {
      for(unsigned k = 0; k < val.get_row; k++)
      {
        result[i][j] += mat[i][k] * val[k][j];
      }
    }
}

Matrix Matrix::dor_multiply_matrix(const Matrix& mat, int col)
{

}

//Matrix subtraction
Matrix Matrix::operator- (const Matrix& mat)
{

}

//Squares each element in the matrix
Matrix Matrix::dot_squared();
{

}
//adds a new column to our matrix
Matrix Matrix::add_new_col(Matrix& mat)
{

}

//Sums up all the values in a columns. Assumes N_col is one
double Matrix::sum_matrix()
{

}

//gets number of rows in matrix
unsigned int Matrix::get_row() const
{
  return N_row;
}

//gets number of columns in matrix
unsigned int Matrix::get_column() const
{
  return N_col;
}
