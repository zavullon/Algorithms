#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int counter = 0;

vector < vector<int> > graph;
vector <int> components;
bool *used;

void dfs(int v)
{
    used[v] = true;
    components[v] = counter;
    for(int i = 0 ; i < graph[v].size() ; i++)
    {
        if(!used[graph[v][i]])
        {
            dfs(graph[v][i]);
        }
    }
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("components.in");
    fout.open("components.out");
    int n , m , x , y;
    fin >> n >> m;
    graph.resize(n);
    components.resize(n , 0);
    used = new bool[n];
    for(int i = 0 ; i < n ; i++)
    {
        used[i] = false;
    }
    for(int i = 0 ; i < m ; i++)
    {
        fin >> x >> y;
        graph[x - 1].push_back(y - 1);
        graph[y - 1].push_back(x - 1);
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(!used[i])
        {
            counter++;
            dfs(i);
        }
    }
    fout << counter << endl;
    for(int i = 0 ; i < components.size() ; i++)
    {
        fout << components[i] << " ";
    }
    fin.close();
    fout.close();
    return 0;
}
