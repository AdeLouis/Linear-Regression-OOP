//Name: Louis Gomez
//Class: Object Oriented Programming
//Class Project

#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <string>

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

Matrix::Matrix(unsigned int r, unsigned int c, vector<vector<int> > m): N_row(r), N_col(c), mat(m)
{}

//copy constructor
Matrix::Matrix(const Matrix& val)
{
  this->mat = val.mat;
  N_row = val.N_row;
  N_col = val.N_col;
}

//Matrix multiplication - add error handling for mismatch dimension
Matrix Matrix::operator* (const vector<vector<int> >& val)
{
  unsigned int new_row = N_row;
  unsigned int new_col = val[0].size();

  //Matrix result(new_row, new_col, 1);
  vector<vector<int> > result(new_row, vector<int>(new_col));
  //add caluclation here
  for (unsigned int i = 0; i < N_row; i++)
  {
    for(unsigned int j = 0; j < val[0].size(); j++)
    {
      for(unsigned int k = 0; k < val.size(); k++)
      {
        result[i][j] += this-> mat[i][k] * val[k][j];
      }
    }
  }
  return Matrix(new_row, new_col, result);
}

int Matrix::operator()(const unsigned int r, const unsigned int c)
{
  return mat[r][c];
}

Matrix Matrix::dot_multiply_matrix(const Matrix& mat, int col)
{

}

//Matrix subtraction
Matrix Matrix::operator- (const Matrix& mat)
{

}

//Squares each element in the matrix
Matrix Matrix::dot_squared()
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
