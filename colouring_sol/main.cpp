
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

int Graph::DSatur()
{
    vector<bool> used(num_of_vertices, false);
    vector<int> colours(num_of_vertices);
    vector<int> degree(num_of_vertices);

    vector<set<int> > adjacent_cols(num_of_vertices);

    //set<key,value>
    //key is the properies of this vertex; maximising saturation makes sure that the vertices are sorted by their saturation
    set<vertex_properites, maximising_saturation> ordered_queue;
    //the first one is the most saturated one (its neighbours are the most coloured -> it has the biggest num of edges -> its numer is bigger

    set<vertex_properites, maximising_saturation>::iterator max_ptr;
    //pointer to vertex


    for (int u = 0; u < num_of_vertices; u++)
    {
        colours[u] = -1; //not coloured yet
        degree[u] = adjacency_mat[u].size(); //how many edges vertex u has
        adjacent_cols[u] = set<int>();

        //initialising
        ordered_queue.emplace(vertex_properites{ 0, degree[u], u });
    }

    while (!ordered_queue.empty()) {

        //cout<<"he"<<endl;
        //TAKE highest saturation vertex
        max_ptr = ordered_queue.begin(); //cuz begin() returns ptr
        int u = (*max_ptr).index;
        ordered_queue.erase(max_ptr);

        for (int v : adjacency_mat[u])
        {
            if (colours[v] != -1)
            {
                used[colours[v]] = true;
            }
        }
           
        int i = 0;
        while (i != used.size())
        {
            if (used[i] == false) //smallest colour that was not yet used
            {
                break;
            }
            i++;
        }
        for (auto v : adjacency_mat[u])
        {
            if (colours[v] != -1)
            {
                used[colours[v]] = false;
            }
        }
       
        colours[u] = i;
        for (auto v : adjacency_mat[u])
        {
            if (colours[v] == -1)
            {
                ordered_queue.erase(
                    {int(adjacent_cols[v].size()),
                        degree[v], v});
                adjacent_cols[v].insert(i);
                degree[v]--;
                ordered_queue.emplace(vertex_properites{
                    int(adjacent_cols[v].size()),
                    degree[v], v});
            }
        }
    }
    
    set<int> ans;
    for (int i = 0; i < num_of_vertices; i++)
    {
        ans.insert(colours[i]); //non-repeating values
    }

//    for (int u = 0; u < num_of_vertices; u++)
//            cout << "V " << u
//                 << " - Col " << colours[u]
//                 << endl;

    return ans.size();
}



int main() {

    int num_of_colours;
    int V;
    int E;
    cin>> V;
    cin>> E;

    Graph Gee(V);

    for(int i = 0; i<E;i++)
    {
        int u,v;
        cin>>u;
        cin>> v;
        Gee.addEdge(u, v);
    }
    //cout<<"nice"<<endl;
    num_of_colours = Gee.DSatur();
    cout<<num_of_colours<<endl;


    return 0;
}
