/*
Name: Louis Gomez
lass: Object Oriented Programming
Class Project
12/3/2018
*/

/*
This is the  class implementation of the linear regression class

  Pseudo Code:
  Class name: Lin_reg
  Data - X_train - holds the training data
        y_train - holds the output values
        theta - holds the parameters for our model

  Public:
    Lin_reg - default constructor

    Functions:
      multiply - multiply vectors
      gradientDescent - find the optimum values for theta
      calc_mean - caluates mean of each columns
      calc_std - finds the standard deviation of each columns
      computeCost - computes cost
      predict - predict values based on inputs
      length - used to get the length of X_train
      featureNormalize - scales and normalizes data
*/

#ifndef _LIN_REG_HPP_
#define _LIN_REG_HPP_

#include <string>
#include <vector>
#include "matrix.hpp"

using std::vector;
using std::string;

class Lin_reg: public Matrix
{
  vector<vector<double> > X_train;
  vector<double> theta;
  vector<double> y_train;

public:
  Lin_reg(unsigned int r, unsigned int n, string file_name);

  vector<double> multiply(Matrix& x, vector<double> val);
  vector<double> gradientDescent(vector<double> theta_x, int iterations, double alpha);
  vector<double> calc_mean(vector<vector<double> > &data);
  vector<double> calc_std(vector<vector<double> > &data, vector<double> val);

  double computeCost(vector<double> theta);
  double predict (vector<double>val);
  double get_theta(int x);
  int length();

  void featureNormalize();
};

#endif
