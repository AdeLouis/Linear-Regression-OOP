
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "matrix.hpp"
#include "lin_reg.hpp"

namespace others
{
  vector<double> getthetainputs(int x)
  {
    vector<double> a(x,0);
    for (int i = 0; i < x; i++)
    {
      std::cout <<"Theta"<<i<<": ";
      std::cin>> a[i];
    }
    return a;
  }

  void displaytheta(vector<double> theta)
  {
    std::cout<<"[ "<<theta[0]<<" "<<theta[1]<<" ]"<<std::endl;
  }
}
//#include "errors.hpp"


int main(void)
{
  string filename;
  int num_rows, num_cols, num_iterations;
  double current_cost, alpha;
  vector<double> test_theta, calc_theta;
  std::cout<<"%--------------------------------------------------------------------------%"<<std::endl;
  std::cout<<"Welcome to the Linear Regression Solver."<<std::endl;
  std::cout<<"This version can be used to solve linear regression problem with one variable."<<std::endl;
  std::cout<<"%--------------------------------------------------------------------------%"<<std::endl;

  try
  {
    std::cout <<"What is the file name: ";
    std::cin >> filename;
    std::cout <<"How many rows: ";
    std::cin >> num_rows;
    std::cout <<"How many columns: ";
    std::cin >> num_cols;

    if (num_cols != 2)
    throw 2;

    std::cout<<"Setting up data model..........."<<std::endl;
  }

  catch(string)
  {
    std::cout<<"Invalid filename"<<std::endl;
    return 0;
  }

  catch(int)
  {
    std::cout <<" Invalid columns length"<<std::endl;
    return 0;
  }
  Lin_reg data(num_rows,num_cols, filename);
  std::cout <<std::endl;
  std::cout<<"%--------------------------------------------------------------------------%"<<std::endl;
  std::cout<<"To minimize our cost function (close to zero), we have to use an optimum value for theta"<<std::endl;
  std::cout<<"To test what our current cost is based on your guess for theta, input in values"<<std::endl;

  test_theta = others::getthetainputs(num_cols);
  current_cost = data.computeCost(test_theta);
  std::cout<<"%--------------------------------------------------------------------------%"<<std::endl;
  std::cout<<"The current cost function based on your theta values is: "<<current_cost<<std::endl;

  std::cout<<"%--------------------------------------------------------------------------%"<<std::endl;
  std::cout<<"To get an optimum value for theta, we run batch gradient descent on our data"<<std::endl;
  std::cout<<"This requires, number of iteration, initial theta and learning rate "<<std::endl;
  std::cout<<"Number of iterations: ";
  std::cin >> num_iterations;
  std::cout<<"Learning Rate(between 0.001 and 0.1): ";
  std::cin >> alpha;
  test_theta = others::getthetainputs(num_cols);
  calc_theta = data.gradientDescent(test_theta,num_iterations,alpha);

  std::cout<<"%--------------------------------------------------------------------------%"<<std::endl;
  std::cout<<"The optimum value for theta with the following parameters:"<<std::endl;
  std::cout<<"Learning rate: "<<alpha<<", Number of iterations: "<<num_iterations<<std::endl;
  others::displaytheta(test_theta);

  std::cout<<"%--------------------------------------------------------------------------%"<<std::endl;
  std::cout<<" Theta for our model is: "<<std::endl;
  others::displaytheta(calc_theta);

  return 0;
}
