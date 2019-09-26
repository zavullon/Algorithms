#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("prefix.in");
    fout.open("prefix.out");
    string str;
    fin >> str;
    vector <int> p(str.length() , 0);
    fout << 0 << " ";
    for(int i = 1 ; i < str.length() ; i++)
    {
        int j = p[i - 1];
        while(j > 0 && str[i] != str[j])
        {
            j = p[j - 1];
        }
        if(str[i] == str[j])
        {
            j++;
        }
        p[i] = j;
        fout << p[i] << " ";
    }
    return 0;
}
