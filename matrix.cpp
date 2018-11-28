//Name: Louis Gomez
//Class: Object Oriented Programming
//Class Project

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

Matrix::Matrix(unsigned int r, unsigned int c, string file_name)
{
  vector<vector<double> > temp(r,vector<double>(c));

  std::ifstream input_file;
  input_file.open(file_name);

  int i = 0;
  string line, mystring;
  if(input_file.is_open())
  {
    N_row = r;
    N_col = c;

        while(getline(input_file,line))
        {
          std::stringstream ss(line);
          getline(ss,mystring, ',');
          temp[i][0] = stod(mystring);

          getline(ss, mystring, ',');
          temp[i][1] = stod(mystring);
          i = i+1;
        }

    }
    this->data = temp;
    input_file.close();
}



Matrix::Matrix(unsigned int r, unsigned int c, vector<double>& m): N_row(r), N_col(c), data_1D(m)
{}

Matrix::Matrix(unsigned int r, unsigned int c, vector<vector<double> >& m):N_row(r), N_col(c), data(m)
{}

Matrix::Matrix(const Matrix& val)
{
  this->data = val.data;
  this->data_1D = val.data_1D;
  N_row = val.N_row;
  N_col = val.N_col;
}

Matrix Matrix::operator* (const vector<double>& val)
{
  unsigned int new_row = N_row;
  unsigned int new_col = 1;

  //cout <<"["<<val[0][1]<<" "<<val[1][1]<<" "<<val[2][1]<<std::endl;
  //Matrix result(new_row, new_col, 1);
  vector<double> result;
  result.resize(new_row);
  //cout<<"row is "<<result.size()<<" col is "<<result[1].size()<<std::endl;

  for (unsigned int i = 0; i < N_row; i++)
  {
    for(unsigned int j = 0; j < N_col; j++)
    {
        result[i] += this-> data[i][j] * val[j];
    }
  }
  return Matrix(new_row, new_col, result);
}

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

double Matrix::operator()(const unsigned int r, const unsigned int c)
{
  return this->data[r][c];
}

Matrix Matrix::dot_multiply(const Matrix& val)
{
  unsigned int new_row = N_row;
  unsigned int new_col = 1;

  vector<double> result;
  result.resize(new_row);

  for (unsigned int i = 0; i < new_row; i++)
  {
      result[i] = this->data_1D[i] * val.data_1D[i];
  }
  return Matrix(new_row, new_col, result);
}

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

Matrix Matrix::add_new_col()
{
  unsigned int row = N_row;
  vector<double> ones;
  vector<vector<double> > result;

  for (unsigned int i = 0; i < N_row; i++)
  {
    ones.push_back(1.0);
    ones.push_back(this->data_1D[i]);
    result.push_back(ones);
    ones.clear();
  }
  return Matrix(row,2,result);
}

unsigned int Matrix::get_row() const
{
  return N_row;
}

//gets number of columns in matrix
unsigned int Matrix::get_column() const
{
  return N_col;
}

double Matrix::sum_matrix()
{
  double result;
  for(unsigned int i = 0; i < N_row; i++)
  {
    result += this->data_1D[i];
  }
  return result;
}
