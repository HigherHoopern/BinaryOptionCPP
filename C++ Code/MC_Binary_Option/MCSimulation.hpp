#ifndef MCSimulation_hpp
#define MCSimulation_hpp

#include <vector>
#include <cstdlib>

using namespace std;

typedef vector<double> PricePath;

class MCSimulation
{
   public:
    double S0, r, V;
    MCSimulation(double S0_, double r_, double V_)
    {S0 = S0_; r = r_; V = V_; srand(10000);}
    // Generate Price Paths
    void GenPricePath(double T,int M,PricePath& S);
};

#endif
