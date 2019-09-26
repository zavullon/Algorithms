#include <iostream>
#include <fstream>

using namespace std;

class Stack
{
    private:
        struct Info
        {
            char c;
            Info *prev;
        };
        Info *head;
    public:
        Stack()
        {
            head = NULL;
        }
        void push(char c);
        char top();
        int isEmpty();
        void pop();
        void free();
        ~Stack()
        {
            while(isEmpty() != 1)
            {
                Info *p = head;
                head = head -> prev;
                delete p;
            }
        }
};

void Stack:: push(char c)
{
    Info *p = new Info;
    p -> c = c;
    p -> prev = head;
    head = p;
}

char Stack:: top()
{
    return head -> c;
}

int Stack:: isEmpty()
{
    return head ? 0 : 1;
}

void Stack:: pop()
{
    if(isEmpty() != 1)
    {
        Info *pv = head;
        head = head -> prev;
        delete pv;
    }
}

void Stack:: free()
{
    while(isEmpty() != 1)
    {
        Info *p = head;
        head = head -> prev;
        delete p;
    }
    head = NULL;
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("brackets.in");
    fout.open("brackets.out");
    Stack A;
    string str;
    int flag = 0;
    while(fin >> str)
    {
        for(int i = 0 ; i < str.length() ; i++)
        {
            if(str[i] == '(' || str[i] == '[')
            {
                A.push(str[i]);
            }
            else
            {
                if(A.isEmpty() || (str[i] == ')' && A.top() != '(') || (str[i] == ']' && A.top() != '['))
                {
                    fout << "NO" << endl;
                    flag = 1;
                    break;
                }
                else
                {
                    A.pop();
                }
            }
        }
        if(flag)
        {
            flag = 0;
            continue;
        }
        if(A.isEmpty())
        {
            fout << "YES" << endl;
        }
        else
        {
            fout << "NO" << endl;
        }
        A.free();
    }
    fin.close();
    fout.close();
    return 0;
}
