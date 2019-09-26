#include <iostream>
#include <fstream>

using namespace std;

long long inv_count = 0;

int n;

void my_merge(int *A , int left , int mid , int right)
{
    int i = 0 , j = 0 , result[right - left] , k = 0;
    while(left + i < mid && mid + j < right)
    {
        if(A[left + i] <= A[mid + j])
        {
            result[i + j] = A[left + i];
            inv_count += j;
            i++;
        }
        else
        {
            result[i + j] = A[mid + j];
            j++;
        }
    }
    while(left + i < mid)
    {
        result[i + j] = A[left + i];
        inv_count += j;
        i++;
    }
    while(mid + j < right)
    {
        result[i + j] = A[mid + j];
        j++;
    }
    for(int k = 0 ; k < i + j ; k++)
    {
        A[left + k] = result[k];
    }
}

void mergesort(int *A , int left , int right)
{
    int i , j;
    for(i = 1 ; i < n ; i *= 2)
    {
        for(j = 0 ; j < n - i ; j += 2 * i)
        {
            my_merge(A , j , j + i , min(j + 2 * i , n));
        }
    }
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("inversions.in");
    fout.open("inversions.out");
    fin >> n;
    int A[n];
    for(int i = 0 ; i < n ; i++)
    {
        fin >> A[i];
    }
    mergesort(A , 0 , n);
    fout << inv_count;
    fin.close();
    fout.close();
    return 0;
}
