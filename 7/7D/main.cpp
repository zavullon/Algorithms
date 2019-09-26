#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 8000000000000000000;

struct edge
{
    int from;
    int to;
    long long weight;
    edge(int f , int t , long long w) :
        from(f)  ,
        to(t)    ,
        weight(w)
    {}
};

vector <edge> graph;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("path.in");
    fout.open("path.out");
    int n , m , start , from , to;
    long long weight;
    vector < vector<int> > adj;
    vector <long long> d;
    vector <int> p;
    vector <bool> nsw;
    fin >> n >> m >> start;
    adj.resize(n);
    d.resize(n , INF);
    p.resize(n , -1);
    nsw.resize(n , false);
    for(int i = 0 ; i < m ; i++)
    {
        fin >> from >> to >> weight;
        graph.push_back(edge(from - 1 , to - 1 , weight));
        adj[from - 1].push_back(to - 1);
    }
    d[start - 1] = 0;
    queue <int> cycle;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < graph.size() ; j++)
        {
            if(d[graph[j].from] < INF && d[graph[j].from] + graph[j].weight < d[graph[j].to])
            {
                d[graph[j].to] = max(-INF , d[graph[j].from] + graph[j].weight);
                if(i == n - 1 || d[graph[j].to] < -INF)
                {
                    cycle.push(graph[j].to);
                }
            }
        }
    }
    while(!cycle.empty())
    {
        from = cycle.front();
        cycle.pop();
        nsw[from] = true;
        for(int i = 0 ; i < adj[from].size() ; i++)
        {
            if(!nsw[adj[from][i]])
            {
                cycle.push(adj[from][i]);
            }
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(nsw[i] || d[i] < -INF)
        {
            fout << '-' << endl;
            continue;
        }
        if(d[i] == INF)
        {
            fout << '*' << endl;
            continue;
        }
        fout << d[i] << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
