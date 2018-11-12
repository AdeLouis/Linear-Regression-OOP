//Name: Louis Gomez
//Class: Object Oriented Programming
//Class Project

#include <vector>
#include <string>
//using namespace std;

class Matrix
{
  unsigned int N_row;       //number of rows
  unsigned int N_col;       //number of columns
  vector<vector <double> > mat;   //2D vector to represent matrix

public:
  //constructor
  Matrix(unsigned int r, unsigned int n, string file_name);
  //Matrix operations
  Matrix operator* (const Matrix& mat);      //Matrix multiplication
  Matrix dot_multiply_matrix (const Matrix& mat, int col);
  Matrix operator- (const Matrix& mat);      //Matrix subtraction
  Matrix dot_squared();                  //Squares each element in the matrix
  Matrix add_new_col (Matrix& mat);

  //Scaler operations
  double sum_matrix();     //Sums the value in a matrix. Assumes N_col = 1

  //other
  unsigned int get_row() const;        //get number of rows
  unsigned int get_column() const;    //get number of columns
};
