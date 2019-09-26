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
        Matrix[x - 1][y - 1] = 1;
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            fout << Matrix[i][j] << " ";
        }
        fout << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
