#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int n , m;
    fin >> n >> m;
    int **graph , start_i , start_j , end_i , end_j , *parents;
    char c;
    queue < pair<int , int> > q;
    graph = new int * [n * m];
    parents = new int[n * m];
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            graph[i * m + j] = new int[5];
            for(int k = 0 ; k < 5 ; k++)
            {
                graph[i * m + j][k] = 0;
            }
            fin >> c;
            if(c != '#')
            {
                if(i - 1 >= 0 && graph[(i - 1) * m + j][0] != -1)
                {
                    graph[(i - 1) * m + j][2] = 1;
                    graph[i * m + j][0] = 1;
                }
                if(j - 1 >= 0 && graph[i * m + j - 1][0] != -1)
                {
                    graph[i * m + j - 1][1] = 1;
                    graph[i * m + j][3] = 1;
                }
                if(c == 'S')
                {
                    start_i = i;
                    start_j = j;
                }
                if(c == 'T')
                {
                    end_i = i;
                    end_j = j;
                }
            }
            else
            {
                graph[i * m + j][0] = -1;
            }
        }
    }
    q.push(make_pair(start_i , start_j));
    graph[start_i * m + start_j][4] = 1;
    parents[start_i * m + start_j] = -1;
    while(!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(i - 1 >= 0 && graph[i * m + j][0] && !graph[(i - 1) * m + j][4])
        {
            graph[(i - 1) * m + j][4] = 1;
            q.push(make_pair(i - 1 , j));
            parents[(i - 1) * m + j] = i * m + j;
        }
        if(i + 1 < n && graph[i * m + j][2] && !graph[(i + 1) * m + j][4])
        {
            graph[(i + 1) * m + j][4] = 1;
            q.push(make_pair(i + 1 , j));
            parents[(i + 1) * m + j] = i * m + j;
        }
        if(j - 1 >= 0 && graph[i * m + j][3] && !graph[i * m + j - 1][4])
        {
            graph[i * m + j - 1][4] = 1;
            q.push(make_pair(i , j - 1));
            parents[i * m + j - 1] = i * m + j;
        }
        if(j + 1 < m && graph[i * m + j][1] && !graph[i * m + j + 1][4])
        {
            graph[i * m + j + 1][4] = 1;
            q.push(make_pair(i , j + 1));
            parents[i * m + j + 1] = i * m + j;
        }
    }
    if(!graph[end_i * m + end_j][4])
    {
        fout << -1;
    }
    else
    {
        string result = "";
        for(int v = end_i * m + end_j ; v != -1 ; v = parents[v])
        {
            if(parents[v] == -1)
            {
                break;
            }
            if(v == parents[v] + 1)
            {
                result = "R" + result;
            }
            if(v == parents[v] - 1)
            {
                result = "L" + result;
            }
            if(v == parents[v] + m)
            {
                result = "D" + result;
            }
            if(v == parents[v] - m)
            {
                result = "U" + result;
            }
        }
        fout << result.size() << endl;
        fout << result;
    }
    fin.close();
    fout.close();
    return 0;
}
