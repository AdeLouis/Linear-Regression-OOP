//Name: Louis Gomez
//Class: Object Oriented Programming
//Class Project

#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::vector;
using std::cout;

//constructor - add error handlin gi file does not exist
Matrix::Matrix(unsigned int r, unsigned int c, string file_name)
{
  std::ifstream input_file;
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
  input_file.close();
}

Matrix::Matrix(unsigned int r, unsigned int c, vector<vector<double> > m): N_row(r), N_col(c), mat(m)
{}

//copy constructor
Matrix::Matrix(const Matrix& val)
{
  this->mat = val.mat;
  N_row = val.N_row;
  N_col = val.N_col;
}

//Matrix multiplication - add error handling for mismatch dimension
Matrix Matrix::operator* (const vector<vector<double> >& val)
{
  unsigned int new_row = N_row;
  unsigned int new_col = val[0].size();

  //Matrix result(new_row, new_col, 1);
  vector<vector<double> > result(new_row, vector<double>(new_col));
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

//Matrix subtraction - add error handling
Matrix Matrix::operator- (const vector<vector<double> >& val)
{
  unsigned int new_row = N_row;
  unsigned int new_col = N_col;

  vector<vector<double> > result(new_row, vector<double>(new_col));

  for (unsigned int i = 0; i < new_row; i++)
  {
    for(unsigned int j = 0; j < new_col; j++)
    {
      result[i][j] = this->mat[i][j] - val[i][j];
    }
  }
  return Matrix(new_row, new_col, result);
}

//Squares each element in the matrix
Matrix Matrix::dot_squared()
{
  vector<vector<double> > result(N_row, vector<double>(N_col));
  for (unsigned int i = 0; i < N_row; i++)
  {
    for(unsigned int j = 0; j < N_col; j++)
    {
      result[i][j] = this->mat[i][j] * this->mat[i][j];
    }
  }
  return Matrix(N_row, N_col, result);
}

//adds a new column to our matrix
void Matrix::add_new_col(int val)
{
  for (unsigned int i = 0; i < N_row; i++)
  {
    mat[i].insert(mat[i].begin(), val);
  }
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

vector<vector<double> > Matrix::get_vector() const
{
  return mat;
}
