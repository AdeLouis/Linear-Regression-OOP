/*
Name: Louis Gomez
lass: Object Oriented Programming
Class Project
12/3/2018
*/

/*
This is the e class implementation of the matrix class

  Pseudo Code:
  Class name: Matrix
  Data - N_row - number of num_rows
         N_col - number of columns
         data_1D - One dimensional represntation of data
         data - 2D reprsentation

  Public:
    Matrix - default constructor
    Matrix - overloaded constructor for initialization with filename
    Matrix - overloaded constructro for initialization with 1D vector
    Matrix - overloaded constructor for deafult initialization with 2D vector
    Matrix - copy constructor

    Functions:
        operator* - Matrix mltiplication with a vector
        operator- Matrix substracting from vector
        operator- Matrix substraction
        operator() - indexing with 1D vector
        operator() - for easy indexing with 2D vector

        dot_multiply - .* for matrix with a vector
        dot_squared - square each elemnt in the matrix
        add_new_col - add a new column to the matrix
        get_row - get th enumber of rows
        get_cloumns - get number of columns
        get_data - get data from class
        subtract - subtract two vectors from each other
        sum_matrix - Sum all columnn in a matrix

*/
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
