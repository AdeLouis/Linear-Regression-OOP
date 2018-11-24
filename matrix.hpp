//Name: Louis Gomez
//Class: Object Oriented Programming
//Class Project

#include <vector>
#include <string>
using std::vector;
using std::string;


class Matrix
{

protected:
  unsigned int N_row;       //number of rows
  unsigned int N_col;       //number of columns
  vector<vector<double> > mat;   //2D vector to represent matrix


public:
  //constructor
  Matrix(unsigned int r, unsigned int n, string file_name);
  Matrix(unsigned int r, unsigned int n, vector<vector<double> > def);
  //Matrix(unsigned int r, unsigned int n, int m);
  Matrix(const Matrix& mat);

  //Matrix operations
  Matrix operator* (const vector<vector<double> >& val);
  int operator() (const unsigned int r, const unsigned int c);
  Matrix dot_multiply_matrix (const Matrix& mat, int col);
  Matrix operator- (const vector<vector<double> >& val);      //Matrix subtraction
  Matrix dot_squared();                  //Squares each element in the matrix
  void add_new_col (int val);  //at the beginning

  //Scaler operations
  double sum_matrix();     //Sums the value in a matrix. Assumes N_col = 1

  //other
  unsigned int get_row() const;        //get number of rows
  unsigned int get_column() const;    //get number of columns
  vector<vector<double> > get_vector() const; //get vector
};
