// BFS - Breath First Search - use queue
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
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

    void bsfTraversal(int src, int n)
    {
        cout<<"=========== BFS ===========\n";
        vector<bool> vis(n + 1, false);
        queue<int> q;
        q.push(src); 
        vis[src] = true;
        
        // cout<<q.front()<<" ";

        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            cout<<t<<" ";
            
            for( auto ele : map[t])
            {
                if(vis[ele] == false){
                q.push(ele);
                vis[ele] = true;
                }
            }
        }
        cout<<endl;
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

    g.bsfTraversal(0, 9);

    return 0;
}