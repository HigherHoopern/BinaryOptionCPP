//
//
//  Created by Jason on 20/04/2021.
//

#ifndef BSModel_hpp
#define BSModel_hpp

// define a class named BS_Model to verify the result of Monte Carol simulations based on Black-Scholes model;
class BSModel{
public:
    // compute binary call option value
    double CallOption(double& S, double& E, double& r, double& T, double& V);
    // compute binary put option value
    double PutOption(double& S, double& E, double& r, double& T, double& V);
};

#endif /* BSModel_hpp */
