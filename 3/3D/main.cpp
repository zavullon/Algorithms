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

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("postfix.in");
    fout.open("postfix.out");
    Stack A;
    char c;
    int x;
    while(fin >> c)
    {
        if(c != ' ')
        {
            if(c >= '0' && c <= '9')
            {
                A.push(c - '0');
            }
            else
            {
                if(c == '-')
                {
                    x = A.top();
                    A.pop();
                    x = A.top() - x;
                    A.pop();
                    A.push(x);
                }
                if(c == '+')
                {
                    x = A.top();
                    A.pop();
                    x = A.top() + x;
                    A.pop();
                    A.push(x);
                }
                if(c == '*')
                {
                    x = A.top();
                    A.pop();
                    x = A.top() * x;
                    A.pop();
                    A.push(x);
                }
            }
        }
    }
    fout << A.top();
    fin.close();
    fout.close();
    return 0;
}
