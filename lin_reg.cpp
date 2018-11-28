//Name: Louis Gomez
//Class: Object Oriented Programming
//Class Project

#include "lin_reg.hpp"
#include <iostream>
#include <string>
#include <vector>

Lin_reg::Lin_reg(unsigned int r, unsigned int n, string file_name): Matrix(r,n,file_name)
{
  unsigned int num_row = r;
  vector<double> temp(num_row,0);
  vector<double> temp2(num_row,0);

  for (unsigned int i = 0; i < num_row; i++)
  {
    temp[i] = get_data(i,0);
    temp2[i] = get_data(i,1);
  }

  X_train = temp;
  y_train = temp2;
}

unsigned int Lin_reg::get_row() const
{
  return Matrix::get_row();
}

unsigned int Lin_reg::get_column() const
{
  return Matrix::get_column();
}

double Lin_reg::get_data(unsigned int a, unsigned int b)
{
  return Matrix::data[a][b];
}

int Lin_reg::length()
{
  return X_train.size();
}

vector<double> Lin_reg::multiply(Matrix &x, vector<double> val)
{
   x*val;
}

double Lin_reg::computeCost(vector<double> val)
{
  int m;
  double j;
  vector<double> h;
  Matrix error,square_error;
  m = length();
  Matrix x (m,1,this->X_train);
  Matrix y (m,1,this->y_train);
  Matrix X_new = x.add_new_col();

  h = multiply(X_new, val);
  Matrix h_new(m,1,h);
  error = (h_new - y);
  square_error = error.dot_squared();
  j = 1 / (2*m) * square_error.sum_matrix();

  return j;
}

double gradientDescent(vector<double> theta, int iterations, double alpha)
{

}

double predict (double val)
{

}
