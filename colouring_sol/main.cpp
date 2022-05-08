
#include <iostream>
#include <map>
#include <math.h>
#include <vector>
#include <iterator>
#include <random>

#include <sstream>
#include <string>
#include <fstream>
using namespace std;
#include <set>
#include <tuple>
#include <vector>

//DSatur algorithm
struct vertex_properites {
    int saturation; // Saturation degree of the vertex
    int degree; // Degree in the uncoloured subgraph
    int index; // Index of vertex
};

struct maximising_saturation{
    bool operator() (const vertex_properites& one, const vertex_properites& two) const
    {
        return tie(one.saturation, one.degree, one.index)
        > tie(two.saturation, two.degree, two.index)
    }
};

int main() {

    int num_of_colours;
    int V;
    int E;
    cin>> V;
    cin>> E;
    
    
    for(int i = 0; i<E;i++)
    {
        
    }
    
    cout<<num_of_colours<<endl;
    
    
    return 0;
}
