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
    temp[i] = data[i][0];
    temp2[i] = data[i][1];
  }

  X_train = temp;
  y_train = temp2;
}
/*
double Lin_reg::get_data(unsigned int a, unsigned int b)
{
  return Matrix::data[a][b];
}
*/
int Lin_reg::length()
{
  return X_train.size();
}

vector<double> Lin_reg::multiply(Matrix &x, vector<double> val)
{
   vector<double> a = x*val;
   //std::cout<<a.size()<<std::endl;
   //std::cout<<a[0]<<" "<<a[1]<<" "<<a[96]<<std::endl;
   return a;
}

double Lin_reg::computeCost(vector<double> val)
{
  int m;
  vector<double> h;
  Matrix error,square_error;
  m = length();

  Matrix X_new ;//= x.add_new_col();
  X_new = add_new_col(X_train);

  h = multiply(X_new, val);
  Matrix h_new(m,1,h);
  error = (h_new - y_train).dot_squared();

  return (1.0 / (2.0*m)) * error.sum_matrix();;
}

double gradientDescent(vector<double> theta, int iterations, double alpha)
{

}

double predict (double val)
{

}
