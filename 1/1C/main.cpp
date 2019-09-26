#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("turtle.in");
    fout.open("turtle.out");
    int i , j , h , w;
    fin >> h >> w;
    int A[h][w] , Ans[h][w];
    for(i = 0 ; i < h ; i++)
    {
        for(j = 0 ; j < w ; j++)
        {
            fin >> A[i][j];
        }
    }
    Ans[h - 1][0] = A[h - 1][0];
    for(i = h - 2 ; i >= 0 ; i--)
    {
        Ans[i][0] = Ans[i + 1][0] + A[i][0];
    }
    for(j = 1 ; j < w ; j++)
    {
        Ans[h - 1][j] = Ans[h - 1][j - 1] + A[h - 1][j];
    }
    for(i = h - 2 ; i >= 0 ; i--)
    {
        for(j = 1 ; j < w ; j++)
        {
            Ans[i][j] = max(Ans[i + 1][j] , Ans[i][j - 1]) + A[i][j];
        }
    }
    fout << Ans[0][w - 1];
    fin.close();
    fout.close();
    return 0;
}
