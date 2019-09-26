#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const long long INF = 9223372036854775807;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("pathmgep.in");
    fout.open("pathmgep.out");
    int n , weight , from , to;
    fin >> n >> from >> to;
    vector < pair<int , int> > graph[n];
    long long dist[n];
    bool used[n];
    for(int i = 0 ; i < n ; i ++)
    {
        dist[i] = INF;
        used[i] = false;
        for(int j = 0 ; j < n ; j++)
        {
            fin >> weight;
            if(weight != -1)
            {
                graph[i].push_back(make_pair(j , weight));
            }
        }
    }
    dist[from - 1] = 0;
    for(int i = 0 ; i < n ; i++)
    {
        int v = -1;
        for(int j = 0 ; j < n ; j++)
        {
            if(!used[j] && (v == -1 || dist[j] < dist[v]))
            {
                v = j;
            }
        }
        if(dist[v] == INF)
        {
            break;
        }
        used[v] = true;
        for(int j = 0 ; j < graph[v].size() ; j++)
        {
            int goal = graph[v][j].first , len = graph[v][j].second;
            if(dist[v] + len < dist[goal])
            {
                dist[goal] = dist[v] + len;
            }
        }
    }
    fout << (dist[to - 1] == INF ? -1 : dist[to - 1]);
    fin.close();
    fout.close();
    return 0;
}
