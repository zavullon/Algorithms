#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("isheap.in");
    fout.open("isheap.out");
    int n;
    fin >> n;
    int *A = new int[n + 1];
    for(int i = 1 ; i <= n ; i++)
    {
        fin >> A[i];
    }
    bool result = true;
    for(int i = 1 ; i <= n ; i++)
    {
        if(i * 2 <= n && A[i] > A[i * 2])
        {
            result = false;
            break;
        }
        if(i * 2 + 1 <= n && A[i] > A[i * 2 + 1])
        {
            result = false;
            break;
        }
    }
    fout << (result ? "YES" : "NO");
    delete [] A;
    fin.close();
    fout.close();
}
