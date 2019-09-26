#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

const long long INF = 9223372036854775807;

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
    fin.open("negcycle.in");
    fout.open("negcycle.out");
    int n , flag;
    long long weight;
    vector <long long> d;
    vector <int> p;
    fin >> n;
    d.resize(n + 1 , INF);
    p.resize(n + 1 , -1);
    for(int i = 0 ; i < n ; i++)
    {
        graph.push_back(edge(n , i , 0));
        for(int j = 0 ; j < n ; j++)
        {
            fin >> weight;
            if(weight == 1000000000)
            {
                continue;
            }
            graph.push_back(edge(i , j , weight));
        }
    }
    d[n] = 0;
    for(int i = 0 ; i < n + 1 ; i++)
    {
        flag = -1;
        for(int j = 0 ; j < graph.size() ; j++)
        {
            if(d[graph[j].from] + graph[j].weight < d[graph[j].to])
            {
                d[graph[j].to] = max(-INF , d[graph[j].from] + graph[j].weight);
                p[graph[j].to] = graph[j].from;
                flag = graph[j].to;
            }
        }
    }
    if(flag != -1)
    {
        int cycle = flag;
        for(int i = 0 ; i < n + 1 ; i++)
        {
            cycle = p[cycle];
        }
        stack <int> result;
        for(int current = cycle ;  ; current = p[current])
        {
            if(current != n)
            {
                result.push(current);
            }
            if(current == cycle && result.size() > 1)
            {
                break;
            }
        }
        fout << "YES" << endl;
        fout << result.size() << endl;
        while(!result.empty())
        {
            fout << result.top() + 1 << " ";
            result.pop();
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
