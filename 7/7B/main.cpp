#include <iostream>
#include <fstream>

using namespace std;

const long long INF = 10000000000;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("pathsg.in");
    fout.open("pathsg.out");
    int n , m , from , to , weight;
    fin >> n >> m;
    long long graph[n][n];
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            graph[i][j] = (i == j ? 0 : INF);
        }
    }
    for(int i = 0 ; i < m ; i++)
    {
        fin >> from >> to >> weight;
        graph[from - 1][to - 1] = weight;
    }
    for(int k = 0 ; k < n ; k++)
    {
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(graph[i][k] != INF && graph[k][j] != INF)
                {
                    graph[i][j] = min(graph[i][j] , graph[i][k] + graph[k][j]);
                }
            }
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            fout << graph[i][j] << " ";
        }
        fout << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
