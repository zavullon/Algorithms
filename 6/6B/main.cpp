#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int n;
    fin >> n;
    int Matrix[n][n];
    bool flag = true;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            fin >> Matrix[i][j];
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j <= i ; j++)
        {
            if(Matrix[i][j] != Matrix[j][i] || (i == j ? Matrix[i][j] : 0))
            {
                flag = false;
                break;
            }
        }
        if(!flag)
        {
            break;
        }
    }
    fout << (flag ? "YES" : "NO");
    fin.close();
    fout.close();
    return 0;
}
