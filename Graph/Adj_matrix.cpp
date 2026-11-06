#include<bits/stdc++.h>
using namespace std;

int main()
{
    int vtx, edg;
    cout<<"Enter number of Vertex & Edges : ";
    cin>>vtx>>edg;

    vector<vector<int>> graph(vtx+1, vector<int>(vtx+1, 0));

    for(int i=0; i<edg; i++)
    {
        int v, u;
        bool flag = 0;
        cin>>v>>u>>flag;
        graph[v][u] = 1;
        if(flag)
        graph[u][v] = 1;
    }

    for(int i=0; i<=vtx; i++)
    {
        for(int j=0; j<=vtx; j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}