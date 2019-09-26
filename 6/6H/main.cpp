#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

enum Color
{
    white ,
    gray  ,
    black ,
};

vector < vector<int> > graph;
vector <Color> color;
vector <int> path;
bool cycle = false , finish = false;
int n , m , c_start , c_end;

void dfs(int v)
{
    color[v] = gray;
    for(int i = 0 ; i < graph[v].size() ; i++)
    {
        if(color[graph[v][i]] == gray)
        {
            c_end = v;
            c_start = graph[v][i];
            cycle = true;
            return;
        }
        if(color[graph[v][i]] == white)
        {
            path[graph[v][i]] = v;
            dfs(graph[v][i]);
            if(cycle)
            {
                return;
            }
        }
    }
    color[v] = black;
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("cycle.in");
    fout.open("cycle.out");
    int from , to;
    fin >> n >> m;
    graph.resize(n);
    color.resize(n , white);
    path.resize(n , 0);
    for(int i = 0 ; i < m ; i++)
    {
        fin >> from >> to;
        graph[from - 1].push_back(to - 1);
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(color[i] == white && !cycle)
        {
            path.clear();
            dfs(i);
        }
    }
    if(cycle)
    {
        fout << "YES" << endl;
        vector <int> result;
        for(int i = c_end ; i != c_start ; i = path[i])
        {
            result.push_back(i);
        }
        result.push_back(c_start);
        for(int i = result.size() - 1 ; i >= 0 ; i--)
        {
            fout << result[i] + 1 << " ";
        }
    }
    else
    {
        fout << "NO";
    }
    fin.close();
    fout.close();
    return 0;
}
