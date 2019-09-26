#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector < pair<int , int> > Queue;

int left(int i)
{
    return (i << 1) + 1;
}

int right(int i)
{
    return (i << 1) + 2;
}

void sift_down(int i)
{
    int smallest;
    if(left(i) < Queue.size() && Queue[left(i)].first < Queue[i].first)
    {
        smallest = left(i);
    }
    else
    {
        smallest = i;
    }
    if(right(i) < Queue.size() && Queue[right(i)].first < Queue[smallest].first)
    {
        smallest = right(i);
    }
    if(i != smallest)
    {
        swap(Queue[i] , Queue[smallest]);
        sift_down(smallest);
    }
}

void sift_up(int i)
{
    while(i != 0 && Queue[i].first < Queue[(i - 1) >> 1].first)
    {
        swap(Queue[i] , Queue[(i - 1) >> 1]);
        i = (i - 1) >> 1;
    }
}

int extract_min()
{
    int minimum = Queue[0].first;
    Queue[0] = Queue[Queue.size() - 1];
    Queue.pop_back();
    sift_down(0);
    return minimum;
}

void element_insert(int x , int i)
{
    Queue.push_back(make_pair(x , i));
    sift_up(Queue.size() - 1);
}

void decrease(int j , int x)
{
    for(int i = 0 ; i < Queue.size() ; i++)
    {
        if(Queue[i].second == j)
        {
            Queue[i].first = x;
            sift_up(i);
            break;
        }
    }
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("priorityqueue.in");
    fout.open("priorityqueue.out");
    string str;
    int x , i = 1 , j;
    while(fin >> str)
    {
        if(str == "push")
        {
            fin >> x;
            element_insert(x , i);
        }
        if(str == "extract-min")
        {
            if(Queue.size() != 0)
            {
                fout << extract_min() << endl;
            }
            else
            {
                fout << '*' << endl;
            }
        }
        if(str == "decrease-key")
        {
            fin >> j >> x;
            decrease(j , x);
        }
        i++;
    }
    fin.close();
    fout.close();
    return 0;
}
