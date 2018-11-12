//Name: Louis Gomez
//Class: Object Oriented Programming
//Class Project

#include "matrix.hpp"
#include <iostream>
#include <fstream>

using namespace std;

//constructor - add error handlin gi file does not exist
Matrix::Matrix(unsigned r, unsigned c, string file_name)
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

//copy constructor
Matrix::Matrix(const Matrix& val)
{
  mat = val.mat;
  N_row = val.N_row;
  N_col = val.N_col;

}

Matrix Matrix::operator* (const Matrix& mat)
{

}

Matrix Matrix::dor_multiply_matrix(const Matrix& mat, int col)
{

}

Matrix Matrix::operator- (const Matrix& mat)
{

}

Matrix Matrix::dot_squared();
{

}

Matrix Matrix::add_new_col(Matrix& mat)
{

}

double Matrix::sum_matrix()
{

}

unsigned int Matrix::get_row() const
{

}

unsigned int Matrix::get_column() const
{

}
