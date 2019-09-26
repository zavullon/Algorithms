#include <iostream>
#include <fstream>

using namespace std;

class Stack
{
    private:
        struct Info
        {
            int x;
            int _min;
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
        int get_min();
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
    p -> _min = isEmpty() ? x : min(head -> _min , x);
    p -> prev = head;
    head = p;
}

int Stack:: top()
{
    if(!isEmpty())
    {
        return head -> x;
    }
}

int Stack:: get_min()
{
    if(!isEmpty())
    {
        return head -> _min;
    }
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

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("queuemin.in");
    fout.open("queuemin.out");
    Stack A , B;
    int n;
    fin >> n;
    char c;
    int x;
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
            if(B.isEmpty())
            {
                while(!A.isEmpty())
                {
                    B.push(A.top());
                    A.pop();
                }
            }
            B.pop();
        }
        if(c == '?')
        {
            if(A.isEmpty() || B.isEmpty())
            {
                fout << (A.isEmpty() ? B.get_min() : A.get_min()) << endl;
            }
            else
            {
                fout << min(A.get_min() , B.get_min()) << endl;
            }
        }
    }
    fin.close();
    fout.close();
    return 0;
}
