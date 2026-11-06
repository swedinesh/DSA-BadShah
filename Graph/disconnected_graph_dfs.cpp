// DFS : Depth First Search
#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    unordered_map<int, vector<int>> map;

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
        for (auto ele : map)
        {
            cout << ele.first << " -> " << "{ ";
            for (auto arr : ele.second)
            {
                cout << arr << ", ";
            }
            cout << "}" << endl;
        }
    }

    void dfsHelper(int src, vector<bool>&vis)
    {
     cout<<src<<" ";
     vis[src] = true;

     for(auto nbr : map[src])
     {
        if(vis[nbr] == false)
        {
            dfsHelper(nbr, vis);
        }
     }

    }

    void dfsTraversal(int src, int n)
    {
      vector<bool>vis(n, false);
        
      // every disconnected graph call
      for(int src=0; src<n; src++)
      {
        if(vis[src]==false)
        dfsHelper(src, vis);
      }
    }
};

int main()
{
     Graph g;
    g.addList(0, 1, 1);
    g.addList(0, 2, 1);
    g.addList(1, 3, 1);
    g.addList(2, 8, 1);
    g.addList(3, 4, 1);
    g.addList(8, 4, 1);
    g.addList(4, 5, 1);
    g.addList(4, 7, 1);
    g.addList(5, 6, 1);
    g.addList(7, 6, 1);

    g.printF();

    g.dfsTraversal(0, 9);
    cout<<endl;

    return 0;
}
