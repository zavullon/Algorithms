#include <iostream>
#include <fstream>

using namespace std;

void siftDown(int *A , int i , int n)
{
    int child;
    int element = A[i];
    while(i <= n >> 1)
    {
        child = i << 1;
        if(child < n && A[child] < A[child + 1])
        {
            child++;
        }
        if(element >= A[child])
        {
            break;
        }
        A[i] = A[child];
        i = child;
    }
    A[i] = element;
}

void heapsort(int *A , int n)
{
    for(int i = (n >> 1) - 1 ; i >= 0 ; i--)
    {
        siftDown(A , i , n - 1);
    }
    for(int i = n - 1 ; i >= 1 ; i--)
    {
        swap(A[0] , A[i]);
        siftDown(A , 0 , i - 1);
    }
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("sort.in");
    fout.open("sort.out");
    int n;
    fin >> n;
    int *A = new int[n];
    for(int i = 0 ; i < n ; i++)
    {
        fin >> A[i];
    }
    heapsort(A , n);
    for(int i = 0 ; i < n ; i++)
    {
        fout << A[i] << " ";
    }
    delete [] A;
    fin.close();
    fout.close();
}
