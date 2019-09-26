#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
    int key;
    Node *left = NULL;
    Node *right = NULL;
};

class Binary_Tree
{
    private:
        Node *root;
    public:
        Binary_Tree() :
            root(NULL)
        {}
        void tree_destroy(Node *leaf);
        void set_root(Node *x);
        Node * get_root() const;
        Node * minimum(Node *x);
        Node * element_insert(Node *x , int key);
        Node * element_search(int key);
        Node * element_delete(Node *x , int key);
        ~Binary_Tree()
        {
            tree_destroy(root);
        }
};

void Binary_Tree:: tree_destroy(Node *leaf)
{
    if(leaf)
    {
        tree_destroy(leaf -> left);
        tree_destroy(leaf -> right);
        delete leaf;
    }
}

void Binary_Tree:: set_root(Node *x)
{
    this -> root = x;
}

Node * Binary_Tree:: get_root() const
{
    return this -> root;
}

Node * Binary_Tree:: minimum(Node *x)
{
    return x -> left ? minimum(x -> left) : x;
}

Node * Binary_Tree:: element_insert(Node *x , int key)
{
    if(!x)
    {
        x = new Node;
        x -> key = key;
        return x;
    }
    else
    {
        if(key < x -> key)
        {
            x -> left = element_insert(x -> left , key);
        }
        if(key > x -> key)
        {
            x -> right = element_insert(x -> right , key);
        }
    }
    return x;
}

Node * Binary_Tree:: element_search(int key)
{
    Node *current = this -> root;
    while(current && current -> key != key)
    {
        current = key < current -> key ? current -> left : current -> right;
    }
    return current;
}

Node * Binary_Tree:: element_delete(Node *x , int key)
{
    if(!x)
    {
        return x;
    }
    if(key < x -> key)
    {
        x -> left = element_delete(x -> left , key);
    }
    else
    {
        if(key > x -> key)
        {
            x -> right = element_delete(x -> right , key);
        }
        else
        {
            if(x -> left && x -> right)
            {
                x -> key = minimum(x -> right) -> key;
                x -> right = element_delete(x -> right , x -> key);
            }
            else
            {
                if(x -> left)
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

int hashfun(int x)
{
    return (x >= 0 ? x : -x) % 10009;
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("set.in");
    fout.open("set.out");
    string str;
    int key , hash_index;
    Binary_Tree *hashset = new Binary_Tree[10009];
    while(fin >> str)
    {
        fin >> key;
        hash_index = hashfun(key);
        if(str == "insert")
        {
            hashset[hash_index].set_root(hashset[hash_index].element_insert(hashset[hash_index].get_root() , key));
        }
        if(str == "delete")
        {
            hashset[hash_index].set_root(hashset[hash_index].element_delete(hashset[hash_index].get_root() , key));
        }
        if(str == "exists")
        {
            Node *tmp = hashset[hash_index].element_search(key);
            fout << (tmp ? "true" : "false") << endl;
        }
    }
    fin.close();
    fout.close();
    return 0;
}
