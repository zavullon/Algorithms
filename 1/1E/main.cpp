#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("sortland.in");
    fout.open("sortland.out");
    int n , i , j , useless;
    fin >> n;
    float A[n] , Num[n];
    for(i = 0 ; i < n ; i++)
    {
        fin >> A[i];
        Num[i] = i + 1;
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
                useless = Num[j];
                Num[j] = Num[j + 1];
                Num[j + 1] = useless;
            }
        }
    }
    fout << Num[0] << " " << Num[n / 2] << " " << Num[n - 1];
    return 0;
}
