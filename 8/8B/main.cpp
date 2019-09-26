#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector <int> prefix_function(string s , int sublen)
{
    int n = s.length();
    vector <int> p(n , 0);
    vector <int> result;
    for(int i = 1 ; i < n ; i++)
    {
        int j = p[i - 1];
        while(j > 0 && s[i] != s[j])
        {
            j = p[j - 1];
        }
        if(s[i] == s[j])
        {
            j++;
        }
        p[i] = j;
        if(p[i] == sublen)
        {
            result.push_back(i - sublen * 2 + 1);
        }
    }
    return result;
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("search2.in");
    fout.open("search2.out");
    string str , sub;
    fin >> sub >> str;
    if(sub.length() <= str.length())
    {
        str = sub + "#" + str;
        vector <int> p;
        p = prefix_function(str , sub.length());
        fout << p.size() << endl;
        for(int i = 0 ; i < p.size() ; i++)
        {
            fout << p[i] << " ";
        }
    }
    else
    {
        fout << 0;
    }
    return 0;
}
