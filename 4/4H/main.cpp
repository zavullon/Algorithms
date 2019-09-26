#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

ifstream fin;
ofstream fout;
vector < pair<string , int> > labels;
vector <string> commands;

class Queue
{
    private:
        struct Node
        {
            int key;
            Node *next = NULL;
        };
        Node *head;
        Node *tail;
    public:
        Queue()
        {
            head = NULL;
            tail = NULL;
        }
        void enqueue(int x);
        bool isEmpty();
        int dequeue();
        ~Queue()
        {
            while(!(this -> isEmpty()))
            {
                Node *tmp = this -> tail;
                this -> tail = this -> tail -> next;
                delete tmp;
            }
        }
};

void Queue:: enqueue(int x)
{
    Node *new_element = new Node;
    new_element -> key = x;
    if(this -> tail == NULL)
    {
        this -> head = new_element;
        this -> tail = new_element;
    }
    else
    {
        this -> head -> next = new_element;
        this -> head = new_element;
    }
}

bool Queue:: isEmpty()
{
    return tail ? false : true;
}

int Queue:: dequeue()
{
    int x;
    if(!(this -> isEmpty()))
    {
        Node *tmp = this -> tail;
        x = tmp -> key;
        this -> tail = this -> tail -> next;
        delete tmp;
    }
    return x;
}

void load()
{
    string str;
    int i = 0;
    while(fin >> str)
    {
        if(str[0] == ':')
        {
            labels.push_back(make_pair(str.substr(1) , i));
        }
        else
        {
            commands.push_back(str);
            i++;
        }
    }
}

int str_to_int(string str)
{
    int result = 0;
    for(int i = 0 ; i < str.length() ; i++)
    {
        result = result * 10 + str[i] - '0';
    }
    return result;
}

int main()
{
    fin.open("quack.in");
    fout.open("quack.out");
    Queue quack;
    load();
    int *reg = new int[26] , x , y;
    char c;
    string current;
    for(int i = 0 ; i < commands.size() ; i++)
    {
        current = commands[i];
        if(current[0] == '>')
        {
            reg[current[1] - 'a'] = quack.dequeue();
            continue;
        }
        if(current[0] == '<')
        {
            quack.enqueue(reg[current[1] - 'a']);
            continue;
        }
        if(current[0] == 'P')
        {
            fout << (current.length() == 1 ? quack.dequeue() : reg[current[1] - 'a']) << endl;
            continue;
        }
        if(current[0] == 'C')
        {
            c = ((current.length() == 1 ? quack.dequeue() : reg[current[1] - 'a']) & 255);
            fout << c;
            continue;
        }
        if(current[0] == 'J')
        {
            for(int j = 0 ; j < labels.size() ; j++)
            {
                if(labels[j].first == current.substr(1))
                {
                    i = labels[j].second - 1;
                    break;
                }
            }
            continue;
        }
        if(current[0] == 'Z')
        {
            if(reg[current[1] - 'a'] == 0)
            {
                for(int j = 0 ; j < labels.size() ; j++)
                {
                    if(labels[j].first == current.substr(2))
                    {
                        i = labels[j].second - 1;
                        break;
                    }
                }
            }
            continue;
        }
        if(current[0] == 'E')
        {
            if(reg[current[1] - 'a'] == reg[current[2] - 'a'])
            {
                for(int j = 0 ; j < labels.size() ; j++)
                {
                    if(labels[j].first == current.substr(3))
                    {
                        i = labels[j].second - 1;
                        break;
                    }
                }
            }
            continue;
        }
        if(current[0] == 'G')
        {
            if(reg[current[1] - 'a'] > reg[current[2] - 'a'])
            {
                for(int j = 0 ; j < labels.size() ; j++)
                {
                    if(labels[j].first == current.substr(3))
                    {
                        i = labels[j].second - 1;
                        break;
                    }
                }
            }
            continue;
        }
        if(current[0] == '+')
        {
            quack.enqueue((quack.dequeue() + quack.dequeue()) & 65535);
            continue;
        }
        if(current[0] == '-')
        {
            quack.enqueue((quack.dequeue() - quack.dequeue()) & 65535);
            continue;
        }
        if(current[0] == '*')
        {
            quack.enqueue((quack.dequeue() * quack.dequeue()) & 65535);
            continue;
        }
        if(current[0] == '/')
        {
            x = quack.dequeue();
            y = quack.dequeue();
            quack.enqueue(y == 0 ? 0 : (x / y) & 65535);
            continue;
        }
        if(current[0] == '%')
        {
            x = quack.dequeue();
            y = quack.dequeue();
            quack.enqueue(y == 0 ? 0 : (x % y) & 65535);
            continue;
        }
        if(current[0] == 'Q')
        {
            break;
        }
        quack.enqueue(str_to_int(current));
    }
    fin.close();
    fout.close();
    return 0;
}
