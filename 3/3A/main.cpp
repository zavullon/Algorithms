#include <iostream>
#include <fstream>

using namespace std;

class Stack
{
    private:
        struct Info
        {
            int x;
            Info *prev = NULL;
        };
        Info *head;
    public:
        Stack()
        {
            head = NULL;
        }
        void push(int x);
        int top();
        bool isEmpty();
        void pop();
        ~Stack()
        {
            while(!isEmpty())
            {
                Info *p = head;
                head = head -> prev;
                delete p;
            }
        }
};

void Stack:: push(int x)
{
    Info *p = new Info;
    p -> x = x;
    p -> prev = head;
    head = p;
}

int Stack:: top()
{
    return head -> x;
}

bool Stack:: isEmpty()
{
    return head ? false : true;
}

void Stack:: pop()
{
    if(!isEmpty())
    {
        Info *pv = head;
        head = head -> prev;
        delete pv;
    }
}

int str_to_int(string str , int k)
{
    int res = 0;
    for(int i = k ; i < str.length() ; i++)
    {
        res = res * 10 + str[i] - '0';
    }
    return res;
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("stack.in");
    fout.open("stack.out");
    Stack A;
    int n;
    fin >> n;
    char c;
    long long x;
    for(int i = 0 ; i < n ; i++)
    {
        fin >> c;
        if(c == '+')
        {
            fin >> x;
            A.push(x);
        }
        if(c == '-')
        {
            fout << A.top() << endl;
            A.pop();
        }
    }
    fin.close();
    fout.close();
    return 0;
}
