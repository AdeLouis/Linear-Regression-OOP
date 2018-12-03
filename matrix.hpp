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
  unsigned int N_row;
  unsigned int N_col;
  vector<double> data_1D;
  vector<vector<double> > data;

public:
  Matrix();
  Matrix(unsigned int r, unsigned int n, string file_name);
  Matrix(unsigned int r, unsigned int n, vector<double> & data);
  Matrix(unsigned int r, unsigned int n, vector<vector<double> >& data);
  Matrix(const Matrix& mat);

  vector<double> operator* (const vector<double>& data);
  Matrix operator- (const vector<double>& data);
  Matrix operator- (const Matrix& data);
  double operator() (const unsigned int r, const unsigned int c);
  double operator() (const unsigned int r);

  Matrix dot_multiply(const vector<vector<double> >& data, int col_num);
  Matrix dot_squared();
  Matrix add_new_col(vector<vector<double> >& val);
  unsigned int get_row() const;
  unsigned int get_column() const;
  vector<vector<double> > get_data() const;
  Matrix subtract(vector<double> a, vector<double> b);
  double sum_matrix();
};

#endif
