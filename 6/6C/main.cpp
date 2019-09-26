#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int n , m , x , y;
    bool flag = false;
    fin >> n >> m;
    int Matrix[n][n];
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            Matrix[i][j] = 0;
        }
    }
    for(int i = 0 ; i < m ; i++)
    {
        fin >> x >> y;
        flag = Matrix[x - 1][y - 1] || Matrix[y - 1][x - 1] ? true : false;
        if(flag)
        {
            break;
        }
        Matrix[x - 1][y - 1] = 1;
    }
    fout << (flag ? "YES" : "NO");
    fin.close();
    fout.close();
    return 0;
}
