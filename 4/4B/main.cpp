#include <iostream>
#include <fstream>

using namespace std;

bool check(int *A , int i , int minimum , int maximum)
{
    if(i == -1)
    {
        return true;
    }
    if(A[3 * i] <= minimum || maximum <= A[3 * i])
    {
        return false;
    }
    return check(A , A[3 * i + 1] - 1 , minimum , A[3 * i])
            && check(A , A[3 * i + 2] - 1 , A[3 * i] , maximum);
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("check.in");
    fout.open("check.out");
    int n , minimum = -1000000001 , maximum = 1000000001;
    fin >> n;
    int *A = new int[3 * n];
    for(int i = 0 ; i < 3 * n ; i++)
    {
        fin >> A[i];
    }
    if(n == 0)
    {
        fout << "YES";
    }
    else
    {
        fout << (check(A , 0 , minimum , maximum) ? "YES" : "NO");
    }
    delete [] A;
    fin.close();
    fout.close();
    return 0;
}
