//Name: Louis Gomez
//Class: Object Oriented Programming
//Class Project

#include "lin_reg.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

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

int Lin_reg::length()
{
  return X_train.size();
}

vector<double> Lin_reg::multiply(Matrix &x, vector<double> val)
{
   return x*val;
}

double Lin_reg::computeCost(vector<double> val)
{
  int m;
  vector<double> h;
  Matrix square_error;
  m = length();

  Matrix X_new ;//= x.add_new_col();
  X_new = add_new_col(X_train);

  h = multiply(X_new, val);
  Matrix h_new(m,1,h);
  square_error = (h_new - y_train).dot_squared();

  return (1.0 / (2.0*m)) * square_error.sum_matrix();
}

vector<double> Lin_reg::gradientDescent(vector<double> theta_x, int num_iterations, double alpha)
{
  int m;
  int i = 0;
  m = length();
  double temp, temp1;
  vector<double> h;
  vector<double> x (N_row,1);

  Matrix X_new,temp2,temp3;
  X_new = add_new_col(X_train);

  while (i < num_iterations)
  {
    h = multiply(X_new, theta_x);
    Matrix error(subtract(h,y_train));
    temp2 = error.dot_multiply(x);
    temp3 = error.dot_multiply(X_train);

    temp = theta_x[0] - ((alpha * (1.0/ m)) * (temp2.sum_matrix()));
    temp1 = theta_x[1] - ((alpha * (1.0/ m)) * (temp3.sum_matrix()));

    theta_x[0] = temp;
    theta_x[1] = temp1;
    i++;
  }
  theta = theta_x;
  cout<<"here"<<endl;
  return theta_x;
}

double Lin_reg::predict(double num)
{
  vector<double> val{1.0,num};
  return (val[0]*theta[0] + val[1]*theta[1]);
}
