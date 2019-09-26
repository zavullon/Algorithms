#include <iostream>
#include <fstream>

using namespace std;

void my_merge(int *A , int left , int mid , int right)
{
    int i = 0 , j = 0 , result[right - left];
    while(left + i <= mid && mid + 1 + j <= right)
    {
        if(A[left + i] < A[mid + 1 + j])
        {
            result[i + j] = A[left + i];
            i++;
        }
        else
        {
            result[i + j] = A[mid + 1 + j];
            j++;
        }
    }
    while(left + i <= mid)
    {
        result[i + j] = A[left + i];
        i++;
    }
    while(mid + 1 + j <= right)
    {
        result[i + j] = A[mid + 1 + j];
        j++;
    }
    for(int k = 0 ; k < i + j ; k++)
    {
        A[left + k] = result[k];
    }
}

void mergesort(int *A , int left , int right)
{
    if(left == right)
    {
        return;
    }
    if(left + 1 == right)
    {
        if(A[left] > A[right])
        {
            int k = A[left];
            A[left] = A[right];
            A[right] = k;
            return;
        }
    }
    int mid = (left + right) / 2;
    mergesort(A , left , mid);
    mergesort(A , mid + 1 , right);
    my_merge(A , left , mid , right);
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("sort.in");
    fout.open("sort.out");
    int n;
    fin >> n;
    int A[n];
    for(int i = 0 ; i < n ; i++)
    {
        fin >> A[i];
    }
    mergesort(A , 0 , n - 1);
    for(int i = 0 ; i < n ; i++)
    {
        fout << A[i] << " ";
    }
    fin.close();
    fout.close();
    return 0;
}
