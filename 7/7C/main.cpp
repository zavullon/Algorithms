#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const long long INF = 9223372036854775807;

vector < pair<long long , int> > d;

int left(int i)
{
    return (i << 1) + 1;
}

int right(int i)
{
    return (i << 1) + 2;
}

void sift_up(int i)
{
    while(i != 0 && d[i].first < d[(i - 1) >> 1].first)
    {
        swap(d[i] , d[(i - 1) >> 1]);
        i = (i - 1) >> 1;
    }
}

void sift_down(int i)
{
    int smallest;
    if(left(i) < d.size() && d[left(i)].first < d[i].first)
    {
        smallest = left(i);
    }
    else
    {
        smallest = i;
    }
    if(right(i) < d.size() && d[right(i)].first < d[smallest].first)
    {
        smallest = right(i);
    }
    if(i != smallest)
    {
        swap(d[i] , d[smallest]);
        sift_down(smallest);
    }
}

void add(int x , int i)
{
    d.push_back(make_pair(x , i));
    sift_up(d.size() - 1);
}

pair<long long , int> extract_min()
{
    pair<long long , int> minimum = d[0];
    swap(d[0] , d[d.size() - 1]);
    d.pop_back();
    sift_down(0);
    return minimum;
}

void decrease_key(int j , long long x)
{
    for(int i = d.size() - 1 ; i >= 0 ; i--)
    {
        if(d[i].second == j)
        {
            d[i].first = x;
            sift_up(i);
            break;
        }
    }
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("pathbgep.in");
    fout.open("pathbgep.out");
    vector < vector< pair<int , int> > > graph;
    int n , m , from , to , weight;
    fin >> n >> m;
    long long result[n];
    graph.resize(n);
    for(int i = 0 ; i < m ; i++)
    {
        fin >> from >> to >> weight;
        graph[from - 1].push_back(make_pair(to - 1 , weight));
        graph[to - 1].push_back(make_pair(from - 1 , weight));
    }
    for(int i = 0 ; i < n ; i++)
    {
        result[i] = INF;
        d.push_back(make_pair(INF , i));
    }
    d[0].first = 0;
    pair<long long , int> v;
    while(d.size() != 0)
    {
        v = extract_min();
        result[v.second] = v.first;
        for(int i = 0 ; i < graph[v.second].size() ; i++)
        {
            if(v.first + graph[v.second][i].second < result[graph[v.second][i].first])
            {
                result[graph[v.second][i].first] = v.first + graph[v.second][i].second;
                decrease_key(graph[v.second][i].first , v.first + graph[v.second][i].second);
            }
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        fout << result[i] << " ";
    }
    fin.close();
    fout.close();
    return 0;
}
