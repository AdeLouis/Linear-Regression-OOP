/*
Name: Louis Gomez
lass: Object Oriented Programming
Class Project
12/3/2018
*/

#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

//Constructors
Matrix::Matrix(): N_row(1), N_col(1)
{}

//overloaded operator -1
Matrix::Matrix(unsigned int r, unsigned int c, string file_name)
{
  vector<vector<double> > temp(r,vector<double>(c));

  std::ifstream input_file;
  input_file.open(file_name);

  if(input_file.is_open())
  {
    int i = 0;
    string line, mystring;

    N_row = r;
    N_col = c;

    while(getline(input_file,line))
    {
      std::stringstream ss(line);
      for(unsigned int k = 0; k < c; k++)
      {
        getline(ss,mystring, ',');
        temp[i][k] = stod(mystring);
      }

      i = i+1;
    }
  }

  this->data = temp;

  input_file.close();

}

//overloaded constructor -1
Matrix::Matrix(unsigned int r, unsigned int c, vector<double>& m): N_row(r), N_col(c), data_1D(m)
{}

//overloaded constructor -3
Matrix::Matrix(unsigned int r, unsigned int c, vector<vector<double> >& m):N_row(r), N_col(c), data(m)
{}

//Copy constructor
Matrix::Matrix(const Matrix& val)
{
  this->data = val.data;
  this->data_1D = val.data_1D;
  N_row = val.N_row;
  N_col = val.N_col;
}

//overloaded operator* to multiply matrix and vector
vector<double> Matrix::operator* (const vector<double>& val)
{
  unsigned int new_row = N_row;
  vector<double> result;
  result.resize(new_row);

  for (unsigned int i = 0; i < N_row; i++)
  {
    for(unsigned int j = 0; j < N_col; j++)
    {
        result[i] += this-> data[i][j] * val[j];
    }
  }
  return result;
}

//overloaded operator- to subtract matrix from matrix
Matrix Matrix::operator- (const Matrix& val)
{
  unsigned int new_row = N_row;
  unsigned int new_col = N_col;

  vector<double> result;
  result.resize(new_row);

  for (unsigned int i = 0; i < new_row; i++)
  {
      result[i] = this->data_1D[i] - val.data_1D[i];
  }
  return Matrix(new_row, new_col, result);
}

//overloaded operator- to subtract matrix from vector
Matrix Matrix::operator- (const vector<double>& val)
{
  unsigned int new_row = N_row;
  unsigned int new_col = N_col;

  vector<double> result;
  result.resize(new_row);

  for (unsigned int i = 0; i < new_row; i++)
  {
      result[i] = this->data_1D[i] - val[i];
  }
  return Matrix(new_row, new_col, result);
}

//overloaded operator() for matrix
double Matrix::operator()(const unsigned int r, const unsigned int c)
{
  return this->data[r][c];
}

//overloaded operator() for 1D vectors
double Matrix::operator()(const unsigned int r)
{
  return this->data_1D[r];
}

//used to .* a matrix and vector
Matrix Matrix::dot_multiply(const vector<vector<double> >& val, int col_num)
{
  unsigned int new_row = N_row;
  unsigned int new_col = 1;

  vector<double> result;
  result.resize(new_row);

  for (unsigned int i = 0; i < new_row; i++)
  {
      result[i] = this->data_1D[i] * val[i][col_num];
  }
  return Matrix(new_row, new_col, result);
}

//Used to square each value in the matrix
Matrix Matrix::dot_squared()
{
  vector<double> result;
  result.resize(N_row);

  for (unsigned int i = 0; i < N_row; i++)
  {
      result[i] = this->data_1D[i] * this->data_1D[i];
  }
  return Matrix(N_row, N_col, result);
}

//accessor fo rnumber of columns
Matrix Matrix::add_new_col(vector<vector<double> >& val)
{
  vector<double> ones;
  vector<vector<double> > result;

  for (unsigned int i = 0; i < N_row; i++)
  {
    ones.push_back(1.0);
    for (unsigned int j = 0; j < N_col; j++)
      ones.push_back(val[i][j]);

    result.push_back(ones);
    ones.clear();
  }
  return Matrix(N_row,2,result);
}

//accessor fo rnumber of rows
unsigned int Matrix::get_row() const
{
  return N_row;
}

//returns the data in matrix
vector<vector<double> > Matrix::get_data() const
{
  return data;
}

//gets number of columns in matrix
unsigned int Matrix::get_column() const
{
  return N_col;
}

//Used to subtract two vectors from each other
Matrix Matrix::subtract(vector<double> a, vector<double> b)
{
  vector<double> result;
  result.resize(a.size());

  for (unsigned int i = 0; i < a.size(); i++)
  {
      result[i] = a[i] - b[i];
  }
  return Matrix(a.size(),1,result);
}

//sums the value in a vector
double Matrix::sum_matrix()
{
  double result;
  for(unsigned int i = 0; i < N_row; i++)
  {
    result += this->data_1D[i];
  }

  return result;
}
