#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int order_statistic(int *ARRAY , int n , int k)
{
    int left = 0 , right = n , mid , i , j , median;
    while(true)
    {
        if(right <= left + 1)
        {
            if(right == left + 1 && ARRAY[left] > ARRAY[right])
            {
                swap(ARRAY[left] , ARRAY[right]);
            }
            return ARRAY[k];
        }
        mid = (left + right) >> 1;
        swap(ARRAY[mid] , ARRAY[left + 1]);
        if(ARRAY[left] > ARRAY[right])
        {
            swap(ARRAY[left] , ARRAY[right]);
        }
        if(ARRAY[left + 1] > ARRAY[right])
        {
            swap(ARRAY[left + 1] , ARRAY[right]);
        }
        if(ARRAY[left] > ARRAY[left + 1])
        {
            swap(ARRAY[left] , ARRAY[left + 1]);
        }
        i = left + 1;
        j = right;
        median = ARRAY[left + 1];
        while(true)
        {
            while(ARRAY[++i] < median);
            while(ARRAY[--j] > median);
            if(i > j)
            {
                break;
            }
            swap(ARRAY[i] , ARRAY[j]);
        }
        ARRAY[left + 1] = ARRAY[j];
        ARRAY[j] = median;
        if(j >= k)
        {
            right = j - 1;
        }
        if(j <= k)
        {
            left = i;
        }
    }
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("kth.in");
    fout.open("kth.out");
    srand(time(0));
    int n , k;
    fin >> n >> k;
    int A , B , C , ARRAY[n];
    fin >> A >> B >> C >> ARRAY[0] >> ARRAY[1];
    for(int i = 2 ; i < n ; i++)
    {
        ARRAY[i] = A * ARRAY[i - 2] + B * ARRAY[i - 1] + C;
    }
    fout << order_statistic(ARRAY , n - 1 , k - 1);
    fin.close();
    fout.close();
    return 0;
}
