#include <iostream>
#include <fstream>

using namespace std;

int n;

void my_merge(string *COUNTRIES , string *RUNNERS , int left , int mid , int right)
{
    int i = 0 , j = 0;
    string result[right - left] , runners_result[right - left];
    while(left + i < mid && mid + j < right)
    {
        if(COUNTRIES[left + i].compare(COUNTRIES[mid + j]) > 0)
        {
            result[i + j] = COUNTRIES[left + i];
            runners_result[i + j] = RUNNERS[left + i];
            i++;
        }
        else
        {
            result[i + j] = COUNTRIES[mid + j];
            runners_result[i + j] = RUNNERS[mid + j];
            j++;
        }
    }
    while(left + i < mid)
    {
        result[i + j] = COUNTRIES[left + i];
        runners_result[i + j] = RUNNERS[left + i];
        i++;
    }
    while(mid + j < right)
    {
        result[i + j] = COUNTRIES[mid + j];
        runners_result[i + j] = RUNNERS[mid + j];
        j++;
    }
    for(int k = 0 ; k < i + j ; k++)
    {
        COUNTRIES[left + k] = result[k];
        RUNNERS[left + k] = runners_result[k];
    }
}

void mergesort(string *COUNTRIES , string *RUNNERS , int left , int right)
{
    int i , j;
    for(i = 1 ; i < n ; i *= 2)
    {
        for(j = 0 ; j < n - i ; j += 2 * i)
        {
            my_merge(COUNTRIES , RUNNERS , j , j + i , min(j + 2 * i , n));
        }
    }
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("race.in");
    fout.open("race.out");
    int i , j;
    fin >> n;
    string COUNTRIES[n] , RUNNERS[n];
    for(i = 0 ; i < n; i++)
    {
        fin >> COUNTRIES[i] >> RUNNERS[i];
    }
    mergesort(COUNTRIES , RUNNERS , 0 , n);
    fout << "=== " << COUNTRIES[n - 1] << " ===" << endl;
    fout << RUNNERS[n - 1] << endl;
    for(i = n - 2 ; i >= 0 ; i--)
    {
        if(COUNTRIES[i + 1] != COUNTRIES[i])
        {
            fout << "=== " << COUNTRIES[i] << " ===" << endl;
        }

        fout << RUNNERS[i] << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
