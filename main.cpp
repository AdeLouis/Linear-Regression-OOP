
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include "matrix.hpp"
#include "lin_reg.hpp"

using std::cout;
using std::endl;
/*
namespace display
{
  void displaydatasubset()
  {

  }
}
*/
int main(void)
{
  double j;
  double alpha = 0.01;
  int num_of_iterations = 1500;
  Lin_reg data(97,2,"foodtruckprofit.txt");
  //cout <<data.get_row()<<endl;
  //cout<<data(0,0)<<endl;
  vector<double> theta{0,0};
  //cout<<theta[0]<<theta[1]<<endl;

  j = data.computeCost(theta);
  cout<<"The cost is: "<<j<<endl;
  vector<double> val = data.gradientDescent(theta, num_of_iterations, alpha);
  cout<<val[0]<<" "<<val[1]<<endl;
  cout<< "Prediction for 3.5 is " << data.predict(3.5)<<endl;

  return 0;
}
