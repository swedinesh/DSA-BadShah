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
            cout << it.first << " -> { ";

            for (auto ele : it.second)
            {
                cout << ele << ", ";
            }

            cout << "}\n";
        }
    }

    bool cycleHelper(int src, unordered_map<int, bool> &vis)
    {
        queue<int> q;
        unordered_map<int, int> parent;

        q.push(src);
        vis[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int temp = q.front();
            q.pop();

            for (auto nbr : map[temp])
            {
                if (!vis[nbr])
                {
                    q.push(nbr);
                    vis[nbr] = true;
                    parent[nbr] = temp;
                }
                else if (nbr != parent[temp])
                {
                    return true;
                }
            }
        }

        return false;
    }

    void cycle()
    {
        bool flag = false;
        unordered_map<int, bool> vis;

        for (auto it : map)
        {
            int node = it.first;

            if (!vis[node])
            {
                if (cycleHelper(node, vis))
                {
                    flag = true;
                    break;
                }
            }
        }

        if (flag)
            cout << "Cycle detected: Graph is cyclic.\n";
        else
            cout << "No cycle detected: Graph is acyclic.\n";
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

    // Uncomment to create a cycle
    // g.addList(5, 6, 0);

    cout << endl;

    g.printF();

    g.cycle();

    return 0;
}