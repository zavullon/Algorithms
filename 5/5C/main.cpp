#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Node
{
    string key;
    string value;
    Node *next;
    Node *linked_next;
    Node *linked_prev;
    explicit
    Node(string key , string value , Node *prev , Node *next)
    :
        next(NULL) ,
        key(key) ,
        value(value) ,
        linked_prev(prev) ,
        linked_next(next)
    {}
};

struct LinkedHashMap
{
    vector <Node *> table;
    Node *head;
    Node *linked_next;
    Node *linked_prev;

    LinkedHashMap()
    {
        linked_next = NULL;
        linked_prev = NULL;
        head = new Node("none" , "none" , NULL , NULL);
        head -> linked_prev = head;
        head -> linked_next = head;
        table.resize(65536);
    }

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

    void add(string key , string value)
    {
        Node *x = get_value(key);
        if(x != NULL)
        {
            x -> value = value;
            return;
        }
        int hash_index = hashfun(key);
        Node *z = new Node(key , value , this -> head -> linked_prev , this -> head);
        this -> head -> linked_prev -> linked_next = z;
        z -> next = table[hash_index];
        table[hash_index] = z;
        this -> head -> linked_prev = z;
    }

    string next(string key)
    {
        Node *x = get_value(key);
        return x ? x -> linked_next -> value : "none";
    }

    string prev(string key)
    {
        Node *x = get_value(key);
        return x ? x -> linked_prev -> value : "none";
    }

    Node *get_value(string key)
    {
        Node *x = table[hashfun(key)];
        while(x != NULL)
        {
            if(x -> key == key)
            {
                return x;
            }
            x = x -> next;
        }
        return NULL;
    }

    string get(string key)
    {
        Node *x = get_value(key);
        return x ? x -> value : "none";
    }

    void element_remove(string key)
    {
        int hash_index = hashfun(key);
        Node *x = table[hash_index];
        Node *prev_x = NULL;
        while(x != NULL)
        {
            if(x -> key == key)
            {
                x -> linked_next -> linked_prev = x -> linked_prev;
                x -> linked_prev -> linked_next = x -> linked_next;
                if(prev_x == NULL)
                {
                    table[hash_index] = x -> next;
                }
                else
                {
                    prev_x -> next = x -> next;
                    x -> next = NULL;
                }
                return;
            }
            prev_x = x;
            x = x -> next;
        }
    }
};

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("linkedmap.in");
    fout.open("linkedmap.out");
    LinkedHashMap lhm;
    string str , key , value;
    while(fin >> str)
    {
        if(str == "put")
        {
            fin >> key >> value;
            lhm.add(key , value);
        }
        if(str == "delete")
        {
            fin >> key;
            lhm.element_remove(key);
        }
        if(str == "get")
        {
            fin >> key;
            fout << lhm.get(key) << endl;
        }
        if(str == "next")
        {
            fin >> key;
            fout << lhm.next(key) << endl;
        }
        if(str == "prev")
        {
            fin >> key;
            fout << lhm.prev(key) << endl;
        }
    }
    return 0;
}
