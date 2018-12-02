//Name: Louis Gomez
//Class: Object Oriented Programming
//Class Project

#ifndef _LIN_REG_HPP_
#define _LIN_REG_HPP_

#include <string>
#include <vector>
#include "matrix.hpp"

using std::vector;
using std::string;

class Lin_reg: public Matrix
{

  vector<double> X_train;
  vector<double> theta;
  vector<double> y_train;
  //vector<double> y_test;

public:
  Lin_reg(unsigned int r, unsigned int n, string file_name);
  //double get_data(unsigned int a, unsigned int b);
  int length();
  vector<double> multiply(Matrix& x, vector<double> val);

  //linear regression core
  double computeCost(vector<double> theta);
  vector<double> gradientDescent(vector<double> theta_x, int iterations, double alpha);
  double predict (double val);
};

#endif
