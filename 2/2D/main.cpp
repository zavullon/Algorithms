#include <iostream>
#include <fstream>

using namespace std;

int n;

void antiQs(int *A)
{
    int useless;
    for(int i = 0 ; i < n ; i++)
    {
        useless = A[i];
        A[i] = A[i / 2];
        A[i / 2] = useless;
    }
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("antiqs.in");
    fout.open("antiqs.out");
    fin >> n;
    int A[n];
    for(int i = 0 ; i < n ; i++)
    {
        A[i] = i + 1;
    }
    antiQs(A);
    for(int i = 0 ; i < n ; i++)
    {
        fout << A[i] << " ";
    }
    fin.close();
    fout.close();
    return 0;
}
