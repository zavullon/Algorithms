#include <iostream>
#include <fstream>

using namespace std;

int height(int *A , int i)
{
    return 1 + max(A[3 * i + 1] ? height(A , A[3 * i + 1] - 1) : -1 , A[3 * i + 2] ? height(A , A[3 * i + 2] - 1) : -1);
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("height.in");
    fout.open("height.out");
    int n;
    fin >> n;
    int *A = new int[3 * n];
    for(int i = 0 ; i < 3 * n ; i++)
    {
        fin >> A[i];
    }
    if(n != 0)
    {
        fout << 1 + height(A , 0);
    }
    else
    {
        fout << 0;
    }
    fin.close();
    fout.close();
    return 0;
}
