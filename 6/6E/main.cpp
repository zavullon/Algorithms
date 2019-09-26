#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

vector < vector<int> > graph;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("pathbge1.in");
    fout.open("pathbge1.out");
    queue <int> q;
    q.push(0);
    int n , m , from , to;
    fin >> n >> m;
    bool used[n];
    int dist[n];
    used[0] = true;
    graph.resize(n);
    for(int i = 0 ; i < n ; i++)
    {
        used[i] = false;
        dist[i] = 0;
    }
    for(int i = 0 ; i < m ; i++)
    {
        fin >> from >> to;
        graph[from - 1].push_back(to - 1);
        graph[to - 1].push_back(from - 1);
    }
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int i = 0 ; i < graph[v].size() ; i++)
        {
            int to = graph[v][i];
            if(!used[to])
            {
                used[to] = true;
                q.push(to);
                dist[to] = dist[v] + 1;
            }
        }
    }
    fout << 0 << " ";
    for(int i = 1 ; i < n ; i++)
    {
        fout << dist[i] << " ";
    }
    fin.close();
    fout.close();
    return 0;
}
