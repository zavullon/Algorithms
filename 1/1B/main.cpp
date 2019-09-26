#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("aplusbb.in");
    fout.open("aplusbb.out");
    long long a , b;
    fin >> a >> b;
    fout << a + b * b;
    fin.close();
    fout.close();
    return 0;
}
