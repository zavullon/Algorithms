#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("smallsort.in");
    fout.open("smallsort.out");
    int n , i , j , useless;
    fin >> n;
    int A[n];
    for(i = 0 ; i < n ; i++)
    {
        fin >> A[i];
    }
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < n - i - 1 ; j++)
        {
            if(A[j] > A[j + 1])
            {
                useless = A[j];
                A[j] = A[j + 1];
                A[j + 1] = useless;
            }
        }
    }
    for(i = 0 ; i < n ; i++)
    {
        fout << A[i] << " ";
    }
    fin.close();
    fout.close();
    return 0;
}
