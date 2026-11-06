#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Graph
{
public:
    unordered_map<int, vector<int>> map;

    // 1 - directed && 0 - undirected
    void addList(int v, int u, bool direction)
    {
        if (direction == 1)
        {
            // directed graph
            map[v].push_back(u);
        }
        else
        {
            // undirected graph
            map[v].push_back(u);
            map[u].push_back(v);
        }
    }

    void printF()
    {
        for(auto ele : map)
        {
            cout<<ele.first<< " -> "<<"{ ";
            for(auto arr : ele.second)
            {
                cout<< arr <<", ";
            }
            cout<<"}"<<endl;
        }
    }
};

int main()
{
    Graph g;
    g.addList(1,5,0);
    g.addList(1,3,0);
    g.addList(2,3,0);
    // g.addList(3,1,0);
    // g.addList(3,2,0);
    g.addList(3,4,0);
    g.addList(3,6,0);
    // g.addList(4,3,0);
    g.addList(4,6,0);
    // g.addList(5,1,0);
    g.addList(5,6,0);
    // g.addList(6,3,0);
    g.addList(7,6,1);
    g.addList(6,2,0);

    g.printF();

    return 0;
}