#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, vector<int>> map;

    void addList(int v, int u, bool dir)
    {
        if (dir == 1)
        {
            map[v].push_back(u);
        }
        else
        {
            map[v].push_back(u);
            map[u].push_back(v);
        }
    }

    void printF()
    {
        for (auto it : map)
        {
            cout << it.first << "->" << "{";
            for (auto ele : it.second)
            {
                cout << ele << ", ";
            }
            cout << "}\n";
        }
    }

    void bfsHelper(int src, unordered_map<int, bool> &vis)
    {

        queue<int> q;
        q.push(src);
        vis[src] = true;

        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            cout << temp << ", ";

            for (auto ele : map[temp])
            {
                if (!vis[ele])
                {
                    q.push(ele);
                    vis[ele] = true;
                }
            }
        }
        cout << endl;
    }

    void bfs(int s)
    {
        unordered_map<int, bool> vis;

        for (int src = s; src < map.size(); src++)
        {
            if (!vis[src])
                bfsHelper(src, vis);
        }
    }
};

int main()
{
    Graph g;
    g.addList(0, 1, 0);
    g.addList(1, 2, 0);
    g.addList(2, 3, 0);
    g.addList(3, 4, 0);
    g.addList(4, 5, 0);
    g.addList(4, 6, 0);
    g.addList(5, 7, 0);
    g.bfs(0);
    g.printF();
    return 0;
}