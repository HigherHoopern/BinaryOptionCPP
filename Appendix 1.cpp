

//
//  main.cpp
//  CPP MC Digital Option
//
//  Created by Jason on 09/04/2021.
//  Sample

#include <cmath>
#include <iostream>
#include <random>
using namespace std;

// define a class named MC_Model to compute the value of binary option
class MC_Model {
private:
// Gaissian Box Muller function, which is to generate normal distribution ramdom variables
double Gauss()
{
    const double pi=4.0*atan(1.0);
    double U1 = (rand()+1.0)/(RAND_MAX+1.0);
    double U2 = (rand()+1.0)/(RAND_MAX+1.0);
    return sqrt(-2.0*log(U1)) * cos(2.0*pi*U2);
}

// Binary Option payoff function
double Heaviside(const double& H) {
  if (H >= 0) {return 1.0;
  } else {
    return 0.0;}
}

public:
// compute binary call option value
double Call_Option( unsigned int& N, double& S0, double& E,
                      double& r,double& sigma,double& T) {
  double ST = 0.0;
  double Payoff_Sum = 0.0;

  for (int i=0; i< N; i++) {
      // Continous Euler-Maruyama Scheme
      ST = S0 * exp(T*(r-0.5*sigma*sigma)+sigma*sqrt(T)*Gauss());
      Payoff_Sum += Heaviside(ST - E); // binary call option payoff
  }
    return (Payoff_Sum / N) * exp(-r*T);
}
    
// compute binary put option value
double Put_Option( unsigned int& N, double& S0,    double& E,
                      double& r,   double& sigma, double& T) {

  double ST = 0.0;
  double Payoff_Sum = 0.0;

  for (int i=0; i< N; i++) {
      // Continous Euler-Maruyama Scheme
      ST = S0 * exp(T*(r-0.5*sigma*sigma)+sigma*sqrt(T)*Gauss());
    Payoff_Sum += Heaviside(E - ST); // binary put option payoff function
  }
  return (Payoff_Sum / N) * exp(-r*T);
}

};

// define a class named BS_Model to verify the result of Monte Carol simulations
// BS_Model class is based on Black-Scholes model;
class BS_Model{
private:
    // define normal cumulative distribution function
    double normalCDF(double x)
    {return erfc(-x / sqrt(2))/2;}
    
public:
    // compute binary call option value
    double Call_Option(double& S, double& E, double& r, double& T, double& sigma){
        double d2;
        d2 = log (S/E) + (r - 0.5*sigma*sigma)*T/sigma*sqrt(T);
        return exp(-r*T)*normalCDF(d2);
    }
    // compute binary put option value
    double Put_Option(double& S, double& E, double& r, double& T, double& sigma){
        double d2;
        d2 = log (S/E) + (r - 0.5*sigma*sigma)*T/sigma*sqrt(T);
        return exp(-r*T)* (1 - normalCDF(d2));
    }
};



int main() {
  
  MC_Model MC; // MC is an object of MS_Model class,
  BS_Model BS; // to verify the output of monte carol simulations
    
  unsigned int N = 100000;  // Number of Monte Carol Simulations = five millions
  double   S = 100.0;       // present stock price = 100
  double   E = 100.0;       // Strike price = 100
  double   r = 0.05;        // Risk-free rate = 5%
  double   sigma = 0.2;     // stock volatility = 20%
  double   T = 1.0;         // time to expiry = 1 year
 
  cout << "Number of Simulations: " << N << endl;
  cout << "Stock Price:     " << S << endl;
  cout << "Strike Price:    " << E << endl;
  cout << "Risk-Free Rate:  " << r << endl;
  cout << "Volatility:      " << sigma << endl;
  cout << "Time_to_Expiry:  " << T << endl << endl;
    
  cout << "Monte Carol Simulation Binary Call Option Value:      "
    << MC.Call_Option(N, S, E, r, sigma, T) << endl;
  cout << "Monte Carol Simulation Binary Put Option Value:       "
    << MC.Put_Option(N, S, E, r, sigma, T ) << endl<<endl;;
  
  cout << "Black Scholes Model Binary Call Option Value:         "
    << BS.Call_Option(S, E, r, T, sigma) << endl;
  cout << "Black Scholes Model Binary Put Option Value:          "
    << BS.Put_Option(S, E, r, T, sigma ) << endl;

  return 0;
}
 
