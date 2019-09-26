#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector < pair<string , string> > A[65536];

int hashfun(string str)
{
    int k = 1 , hash_index = 0;
    for(int i = 0 ; i < str.length() ; i++)
    {
        hash_index += str[i] * k;
        k *= 31;
    }
    return hash_index & 65535;
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("map.in");
    fout.open("map.out");
    string str , key , value;
    bool exists;
    int hash_index;
    while(fin >> str)
    {
        if(str == "put")
        {
            fin >> key >> value;
            hash_index = hashfun(key);
            exists = false;
            for(int i = 0 ; i < A[hash_index].size() ; i++)
            {
                if(A[hash_index][i].first == key)
                {
                    exists = true;
                    A[hash_index][i].second = value;
                    break;
                }
            }
            if(!exists)
            {
                A[hash_index].push_back(make_pair(key , value));
            }
        }
        if(str == "delete")
        {
            fin >> key;
            hash_index = hashfun(key);
            for(int i = 0 ; i < A[hash_index].size() ; i++)
            {
                if(A[hash_index][i].first == key)
                {
                    A[hash_index].erase(A[hash_index].begin() + i);
                }
            }
        }
        if(str == "get")
        {
            fin >> key;
            hash_index = hashfun(key);
            exists = false;
            for(int i = 0 ; i < A[hash_index].size() ; i++)
            {
                if(A[hash_index][i].first == key)
                {
                    exists = true;
                    fout << A[hash_index][i].second << endl;
                    break;
                }
            }
            if(!exists)
            {
                fout << "none" << endl;
            }
        }
    }
    fin.close();
    fout.close();
    return 0;
}
