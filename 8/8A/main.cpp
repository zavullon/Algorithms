#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("search1.in");
    fout.open("search1.out");
    bool flag;
    string str , substring;
    vector <int> result;
    fin >> substring >> str;
    if(substring.length() > str.length())
    {
        fout << 0;
        return 0;
    }
    for(int i = 0 ; i < str.size() - substring.size() + 1 ; i++)
    {
        flag = true;
        for(int j = 0 ; j < substring.size() ; j++)
        {
            if(substring[j] != str[i + j])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            result.push_back(i + 1);
        }
    }
    fout << result.size() << endl;
    for(int i = 0 ; i < result.size() ; i++)
    {
        fout << result[i] << " ";
    }
    fin.close();
    fout.close();
    return 0;
}
