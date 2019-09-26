#include <iostream>
#include <fstream>

using namespace std;

int n , m;

char digit(string str , int i)
{
    return str[i];
}

void radix_sort(string *A , int k)
{
    int C[m];
    string B[n];
    for(int i = 0 ; i < m ; i++)
    {
        C[i] = 0;
    }
    for(int i = 0 ; i < n ; i++)
    {
        C[digit(A[i] , k) - 'a']++;
    }
    for(int i = 1 ; i < m ; i++)
    {
        C[i] += C[i - 1];
    }
    for(int i = n - 1 ; i >= 0 ; i--)
    {
        B[C[digit(A[i] , k) - 'a'] - 1] = A[i];
        C[digit(A[i] , k) - 'a']--;
    }
    for(int i = 0 ; i < n ; i++)
    {
        A[i] = B[i];
    }
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("radixsort.in");
    fout.open("radixsort.out");
    int k;
    fin >> n >> m >> k;
    string STR[n];
    for(int i = 0 ; i < n ; i++)
    {
        fin >> STR[i];
    }
    for(int i = m - 1 ; i > m - 1 - k ; i--)
    {
        radix_sort(STR , i);
    }
    for(int i = 0 ; i < n ; i++)
    {
        fout << STR[i] << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
