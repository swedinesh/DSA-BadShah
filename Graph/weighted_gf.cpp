#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Graph
{
public:
    unordered_map<int, vector< pair<int, int> > > map;

    // 1 - directed && 0 - undirected
    void addList(int u, int v, int wt, bool direction)
    {
        if (direction == 1)
        {
            // directed graph
            map[u].push_back(make_pair(wt, v));
            // map[v].push_back(p);
        }
        else
        {
            // undirected graph
             map[u].push_back(make_pair(wt, v));
             map[v].push_back(make_pair(wt, u));
            
        }
    }

    void printF()
    {
        for(auto ele : map)
        {
            cout<<ele.first<< " -> "<<"{";
            for(auto arr : ele.second)
            {
                cout<< "(w:"<<arr.first <<", "<<arr.second<<"), ";
            }
            cout<<" }"<<endl;
        }
    }
};

int main()
{
    Graph g;
  
    g.addList(1,2,5,0); // 1->2
    g.addList(2,3,3,0); // 2->3
    g.addList(3,4,1,0); // 3->4
    g.addList(4,1,3,0); // 4->1
    g.printF();

    return 0;
}