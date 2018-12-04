
/*
Name: Louis Gomez
lass: Object Oriented Programming
Class Project
12/3/2018
*/

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

  void displaytheta(vector<double> theta, int x)
  {
    for (int i = 0; i < x; i++)
    {
      std::cout<<"theta "<<i<<" : "<<theta[i]<<std::endl;
    }
  }

  vector<double> getpredictvalues(int x)
  {
    vector<double> a(x-1,0);
    for (int i = 0; i < x-1; i++)
    {
      std::cout <<"Feature "<<i+1<<": ";
      std::cin>> a[i];
    }
    return a;
  }

  int main_menu()
  {
    int input;

    std::cout<<"Select an option below to proceed from the options below:"<<std::endl;
    std::cout<<"1. Normalize Features"<<std::endl; //add error handling
    std::cout<<"2. Compute Cost for specific theta values"<<std::endl;
    std::cout<<"3. Perform Gradient Descent to get optimum theta"<<std::endl;
    std::cout<<"4. Predict a Value"<<std::endl;
    std::cout<<"5. Exit the solver"<<std::endl;

    std::cout<<"What is your choice: ";
    std::cin>>input;

    return input;
  }
}

int main(void)
{
  string filename;
  int num_rows, num_cols,num_iterations,option;
  double current_cost, alpha;
  vector<double> test_theta, calc_theta, predict_values;
  std::cout<<"%--------------------------------------------------------------------------%"<<std::endl;
  std::cout<<"Welcome to the Linear Regression Solver."<<std::endl;
  std::cout<<"This version can be used to solve linear regression problem with one variable."<<std::endl;
  std::cout<<"%--------------------------------------------------------------------------%"<<std::endl;

  std::cout <<"What is the file name: ";
  std::cin >> filename;
  std::cout <<"How many rows: ";
  std::cin >> num_rows;
  std::cout <<"How many columns: ";
  std::cin >> num_cols;

  std::cout<<"Setting up data model..........."<<std::endl;
  Lin_reg data(num_rows,num_cols, filename);

  do{
    try
    {
      option = others::main_menu();

      if(option > 5 || option < 1)
        throw option;

      switch(option)
      {

        case 1:
          std::cout<<"%--------------------------------------------------------------------------%"<<std::endl;
          std::cout<<"Feature Normalization is vital "
                    "when you have more than one feature"<<std::endl;

          data.featureNormalize();
        break;

        case 2:
          std::cout<<"%--------------------------------------------------------------------------%"<<std::endl;
          std::cout<<"To minimize our cost function (close to zero), we have to use an optimum value for theta"<<std::endl;
          std::cout<<"To test what our current cost is based on your guess for theta, input in values"<<std::endl;

          test_theta = others::getthetainputs(num_cols);
          current_cost = data.computeCost(test_theta);
          std::cout<<"%--------------------------------------------------------------------------%"<<std::endl;
          std::cout<<"The current cost based on your theta values is: "<<current_cost<<std::endl;
        break;

        case 3:
          std::cout<<"%--------------------------------------------------------------------------%"<<std::endl;
          std::cout<<"To get an optimum value for theta, we run batch gradient descent on our data"<<std::endl;
          std::cout<<"This requires, number of iteration, initial theta and learning rate "<<std::endl;
          std::cout<<"Number of iterations: ";
          std::cin >> num_iterations;
          std::cout<<"Learning Rate(between 0.001 and 0.1): ";
          std::cin >> alpha;
          test_theta = others::getthetainputs(num_cols);
          calc_theta = data.gradientDescent(test_theta,num_iterations,alpha);

          others::displaytheta(calc_theta, num_cols);
          std::cout<<"New cost is: "<<data.computeCost(calc_theta)<<std::endl;
          std::cout<<std::endl;
        break;

        case 4:
          std::cout<<"%--------------------------------------------------------------------------%"<<std::endl;
          std::cout<<"Lets predict some values"<<std::endl;
          predict_values = others::getpredictvalues(num_cols);
          std::cout<<"Predicted amount = $"<<data.predict(predict_values)<<std::endl;
        break;

        default:
          std::cout<<"Thanks for using the solver"<<std::endl;
          std::ofstream output;
          output.open("Parameters Calculated.txt");

          output<<"Name: "<<filename<<std::endl;
          output<<"Optimal Theta Calulated are: "<<std::endl;

          for (int i = 0; i < num_cols ; i++)
          {
            output<<"Theta "<<i<<": "<<data.get_theta(i)<<std::endl;
          }

          output.close();
        break;
      }
    }
    catch(int option)
    {
      std::cout<<"Invalid menu option"<<std::endl;
    }

  }while(option != 5);

  return 0;
}
