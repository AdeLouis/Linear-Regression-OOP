/*
Name: Louis Gomez
lass: Object Oriented Programming
Class Project
12/3/2018
*/

#include "lin_reg.hpp"
#include "meanstd.h"
#include <math.h>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
Meanstd variables;

//Constructor
Lin_reg::Lin_reg(unsigned int row, unsigned int col, string file_name): Matrix(row,col,file_name)
{
  vector<vector<double> > temp(row,vector<double>(col-1));
  vector<double> temp2(row,0);

  for (unsigned int i = 0; i < row; i++)
  {
    for(unsigned int j = 0; j < col-1; j++)
    {
      temp[i][j] = data[i][j];
    }
    temp2[i] = data[i][col-1];
  }
  this->X_train = temp;
  this->y_train = temp2;
}

//gets the size of the X_train
int Lin_reg::length()
{
  return X_train.size();
}

//Used to multiply a Matrix and vector
vector<double> Lin_reg::multiply(Matrix &x, vector<double> val)
{
   return x*val;
}

//Computes the cost function for our model
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

//Calculates the optimum thet avalue using gradient descent algorithm
vector<double> Lin_reg::gradientDescent(vector<double> theta_x, int num_iterations, double alpha)
{
  int m;
  int i = 0;
  m = length();
  vector<double> h;
  vector<double> x (N_row,1);

  Matrix X_new,temp2,temp3;
  X_new = add_new_col(X_train);

  while (i < num_iterations)
  {
    h = multiply(X_new, theta_x);
    Matrix error(subtract(h,y_train));

    for(unsigned int j = 0; j < X_new.get_column(); j++)
    {
      temp3 = error.dot_multiply(X_new.get_data(),j);
      theta_x[j] = theta_x[j] - ((alpha * (1.0/ m)) * (temp3.sum_matrix()));
    }
    i++;
  }

  theta = theta_x;
  return theta_x;
}

//Scales and normalizes our data
void Lin_reg::featureNormalize()
{
  static unsigned int call_count = 0;
  if (call_count == 0)
  {
    variables.mean = calc_mean(X_train);
    variables.standard_dev = calc_std(X_train, variables.mean);

    for(unsigned int i = 0; i < X_train[0].size(); i++)
    {
      for(unsigned int j = 0; j < X_train.size(); j++)
      {
        X_train[j][i] = X_train[j][i] - variables.mean[i];
        X_train[j][i] = X_train[j][i] / variables.standard_dev[i];
      }
    }
  }
  call_count++;
}

//Used to predict the value for our model
double Lin_reg::predict(vector<double> predict)
{
  if (predict.size() > 1)
  {
    double temp;
    for(unsigned int i = 0; i <predict.size(); i++)
    {
      temp = predict[i] - variables.mean[i];
      predict[i] = temp / variables.standard_dev[i];
    }
  }
  vector<double> val{1.0};
  double value = 0;
  for(unsigned int i = 0; i <predict.size(); i++)
    val.push_back(predict[i]);

  for(unsigned int i = 0; i < val.size(); i++)
    value = value + (val[i]*theta[i]);

  return value;
}

//calculates the mean value of each column in a matrix
vector<double> Lin_reg::calc_mean(vector<vector<double> > &data)
{
  vector<double> result(data[0].size(),1);
  double temp = 0.0;
  for(unsigned int i = 0; i < data[0].size(); i++)
  {
    for(unsigned int j = 0; j < data.size(); j++)
    {
      temp = temp + data[j][i];
    }
    result[i] = temp/data.size();
    temp = 0.0;
  }
  return result;
}

//calulates the standard deviation of each column in our model
vector<double> Lin_reg::calc_std(vector<vector<double> > &data, vector<double> val)
{
  vector<vector<double> > temp = data;
  double temp1;
  vector<double> temp_mean(data[0].size());
  vector<double> std(data[0].size());

  for(unsigned int i = 0; i < data[0].size(); i++)
  {
    for(unsigned int j = 0; j < data.size(); j++)
    {
      temp1 = data[j][i] - val[i];
      temp[j][i] = temp1 * temp1;
    }
  }

  temp_mean = calc_mean(temp);

  for (unsigned i = 0; i < temp_mean.size(); i++)
  {
    std[i] = sqrt(temp_mean[i]);
  }
  return std;
}

//used to access the value of theta
double Lin_reg::get_theta(int x)
{
  return theta[x];
}
