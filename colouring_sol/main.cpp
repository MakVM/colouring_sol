
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
        > tie(two.saturation, two.degree, two.index);
        //creates a tuple and compares one by one
        //if there is an equal saturation, then it compares their degrees (how many edges it has, if those are equal as well, it compares their indices
        
    }
};

class Graph {
 
    int num_of_vertices;
    vector<vector<int> > adjacency_mat;
 
public:
    //construct
    Graph(int V)
    {
        num_of_vertices = V;
        adjacency_mat.resize(num_of_vertices, vector<int>());
    }
    
    //destruct
    ~Graph() { adjacency_mat.clear(); }
 

    void addEdge(int u, int v);
 
    int DSatur(); //returns the min num of colours required to colour the graph
};
 
void Graph::addEdge(int u, int v)
{
    adjacency_mat[u].push_back(v);
    adjacency_mat[v].push_back(u);
    //this way it's a symmetrical matrix
}




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
