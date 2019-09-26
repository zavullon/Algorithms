#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("aplusb.in");
    fout.open("aplusb.out");
    int a , b;
    fin >> a >> b;
    fout << a + b;
    fin.close();
    fout.close();
    return 0;
}
