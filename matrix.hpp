//Name: Louis Gomez
//Class: Object Oriented Programming
//Class Project

#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include <vector>
#include <string>
using std::vector;
using std::string;


class Matrix
{

protected:
  unsigned int N_row;       //number of rows
  unsigned int N_col;       //number of columns
  vector<double> data_1D;
  vector<vector<double> > data;   //2D vector to represent matrix

public:
  //constructor
  Matrix();
  Matrix(unsigned int r, unsigned int n, string file_name);
  Matrix(unsigned int r, unsigned int n, vector<double> & data);
  Matrix(unsigned int r, unsigned int n, vector<vector<double> >& data);
  //Matrix(unsigned int r, unsigned int n, int m);
  Matrix(const Matrix& mat);

  vector<double> operator* (const vector<double>& data);
  Matrix operator- (const vector<double>& data);
  Matrix operator- (const Matrix& data);
  double operator() (const unsigned int r, const unsigned int c);
  double operator() (const unsigned int r);
  Matrix dot_multiply(const vector<double>& data);
  Matrix dot_squared();

  Matrix add_new_col(vector<double>& val);
  unsigned int get_row() const;        //get number of rows
  unsigned int get_column() const;    //get number of columns
  Matrix subtract(vector<double> a, vector<double> b);
  double sum_matrix();     //Sums the value in a matrix. Assumes N_col
};

#endif
