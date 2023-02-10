//
//  MathLib.cpp
//  BinOption_ref_main19
//
//  Created by Jason on 21/04/2021.
//

#include "MathLib.hpp"
#include <cmath>

// generate samples of random variables with standard normal
// distribution. Box–Muller method

double Gauss()
{   const double pi=4.0*atan(1.0);
    double U1 = (rand()+1.0)/(RAND_MAX+1.0);
    double U2 = (rand()+1.0)/(RAND_MAX+1.0);
    return sqrt(-2.0*log(U1)) * cos(2.0*pi*U2);
}

// define normal cumulative distribution function
double NormalCDF(double x){
    return erfc(-x / sqrt(2))/2;
}
