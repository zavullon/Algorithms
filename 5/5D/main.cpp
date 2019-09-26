#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream fin;
ofstream fout;
bool element_exists;

struct Node;

class Binary_Tree
{
    private:
        Node *root;
        int tree_size;
    public:
        Binary_Tree()
        {
            root = NULL;
            tree_size = 0;
        }
        void tree_traversal(Node *x);
        int get_size();
        void dec_size();
        void * set_root(Node *x);
        Node * get_root();
        Node * minimum(Node *x);
        Node * exists(string x);
        Node * element_insert(Node *x , string z , string a);
        Node * value_insert(Node *x , string z);
        Node * element_delete(Node *x , string z);
        void delete_by_value(string z , string a);
        void get(string z);
        void tree_delete(Node *leaf);
        ~Binary_Tree()
        {
            tree_delete(root);
        }
};

struct Node
{
    string key;
    Binary_Tree values;
    Node *left = NULL;
    Node *right = NULL;
};

void Binary_Tree:: dec_size()
{
    this -> tree_size--;
}

int Binary_Tree:: get_size()
{
    return this -> tree_size;
}

void Binary_Tree:: tree_traversal(Node *x)
{
    if(x != NULL)
    {
        tree_traversal(x -> right);
        fout << x -> key << " ";
        tree_traversal(x -> left);
    }
}

Node * Binary_Tree:: get_root()
{
    return this -> root;
}

void * Binary_Tree:: set_root(Node *x)
{
    this -> root = x;
}

Node * Binary_Tree:: minimum(Node *x)
{
    return x -> left ? minimum(x -> left) : x;
}

Node * Binary_Tree:: exists(string x)
{
    Node *current = this -> root;
    while(current != NULL && (current -> key).compare(x) != 0)
    {
        current = (current -> key).compare(x) > 0 ? current -> left : current -> right;
    }
    return current;
}

Node * Binary_Tree:: value_insert(Node *x , string z)
{
    if(x == NULL)
    {
        x = new Node;
        x -> left = NULL;
        x -> right = NULL;
        x -> key = z;
        this -> tree_size++;
        return x;
    }
    else
    {
        if(z.compare(x -> key) < 0)
        {
            x -> left = value_insert(x -> left , z);
        }
        if(z.compare(x -> key) > 0)
        {
            x -> right = value_insert(x -> right , z);
        }
    }
    return x;
}

Node * Binary_Tree:: element_insert(Node *x , string z , string a)
{
    if(x == NULL)
    {
        x = new Node;
        x -> left = NULL;
        x -> right = NULL;
        x -> key = z;
        (x -> values).set_root((x -> values).value_insert((x -> values).get_root() , a));
        return x;
    }
    else
    {
        if(z.compare(x -> key) == 0)
        {
            (x -> values).set_root((x -> values).value_insert((x -> values).get_root() , a));
        }
        if(z.compare(x -> key) < 0)
        {
            x -> left = element_insert(x -> left , z , a);
        }
        if(z.compare(x -> key) > 0)
        {
            x -> right = element_insert(x -> right , z , a);
        }
    }
    return x;
}

Node * Binary_Tree:: element_delete(Node *x , string z)
{
    if(x == NULL)
    {
        return x;
    }
    if(z.compare(x -> key) < 0)
    {
        x -> left = element_delete(x -> left , z);
    }
    else
    {
        if(z.compare(x -> key) > 0)
        {
            x -> right = element_delete(x -> right , z);
        }
        else
        {
            element_exists = true;
            if(x -> left != NULL && x -> right != NULL)
            {
                x -> key = minimum(x -> right) -> key;
                x -> right = element_delete(x -> right , x -> key);
            }
            else
            {
                if(x -> left != NULL)
                {
                    x = x -> left;
                }
                else
                {
                    x = x -> right;
                }
            }
        }
    }
    return x;
}

void Binary_Tree:: delete_by_value(string z , string a)
{
    Node *x = this -> exists(z);
    if(x != NULL)
    {
        element_exists = false;
        (x -> values).set_root((x -> values).element_delete((x -> values).get_root() , a));
        if(element_exists)
        {
            (x -> values).dec_size();
        }
    }
}

void Binary_Tree:: get(string z)
{
    Node *x = this -> exists(z);
    if(x != NULL)
    {
        fout << (x -> values).get_size() << " ";
        (x -> values).tree_traversal((x -> values).get_root());
        fout << endl;
    }
    else
    {
        fout << 0 << endl;
    }
}

void Binary_Tree:: tree_delete(Node *leaf)
{
    if(leaf != NULL)
    {
        tree_delete(leaf -> left);
        tree_delete(leaf -> right);
        delete leaf;
    }
}

int hashfun(string str)
{
    int k = 1 , hash_index = 0;
    for(int i = 0 ; i < str.length() ; i++)
    {
        hash_index += str[i] * k;
        k *= 31;
    }
    return hash_index & 1048575;
}

int main()
{
    fin.open("multimap.in");
    fout.open("multimap.out");
    Binary_Tree *multi = new Binary_Tree[1048576];
    string str , key , value;
    int hash_index;
    while(fin >> str)
    {
        if(str == "put")
        {
            fin >> key >> value;
            hash_index = hashfun(key);
            multi[hash_index].set_root(multi[hash_index].element_insert(multi[hash_index].get_root() , key , value));
        }
        if(str == "delete")
        {
            fin >> key >> value;
            hash_index = hashfun(key);
            multi[hash_index].delete_by_value(key , value);
        }
        if(str == "deleteall")
        {
            fin >> key;
            hash_index = hashfun(key);
            multi[hash_index].set_root(multi[hash_index].element_delete(multi[hash_index].get_root() , key));
        }
        if(str == "get")
        {
            fin >> key;
            hash_index = hashfun(key);
            multi[hash_index].get(key);
        }
    }
    fin.close();
    fout.close();
    return 0;
}
