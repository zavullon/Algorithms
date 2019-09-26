#include <iostream>
#include <vector>
#include <stack>
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
stack <int> result;
bool cycle = false;
int n , m;

void dfs(int v)
{
    color[v] = gray;
    for(int i = 0 ; i < graph[v].size() ; i++)
    {
        if(color[graph[v][i]] == gray)
        {
            cycle = true;
        }
        if(color[graph[v][i]] == white)
        {
            dfs(graph[v][i]);
        }
    }
    result.push(v);
    color[v] = black;
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("topsort.in");
    fout.open("topsort.out");
    int from , to;
    fin >> n >> m;
    graph.resize(n);
    color.resize(n);
    for(int i = 0 ; i < m ; i++)
    {
        fin >> from >> to;
        graph[from - 1].push_back(to - 1);
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(cycle)
        {
            break;
        }
        if(color[i] == white)
        {
            dfs(i);
        }
    }
    if(!cycle)
    {
        while(!result.empty())
        {
            fout << result.top() + 1 << " ";
            result.pop();
        }
    }
    else
    {
        fout << -1;
    }
    fin.close();
    fout.close();
    return 0;
}
