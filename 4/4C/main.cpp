#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
    int key;
    Node *left = NULL;
    Node *right = NULL;
    Node *parent = NULL;
};

class Binary_Tree
{
    private:
        Node *root;
    public:
        Binary_Tree()
        {
            root = NULL;
        }
        void * set_root(Node *x);
        Node * get_root();
        Node * minimum(Node *x);
        Node * maximum(Node *x);
        Node * next(int x);
        Node * prev(int x);
        Node * exists(int x);
        Node * element_insert(Node *x , int z);
        Node * element_delete(Node *x , int z);
        void tree_delete(Node *leaf);
        ~Binary_Tree()
        {
            tree_delete(root);
        }
};

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

Node * Binary_Tree:: maximum(Node *x)
{
    return x -> right ? maximum(x -> right) : x;
}

Node * Binary_Tree:: next(int x)
{
    Node *current = this -> root , *successor = NULL;
    while(current != NULL)
    {
        if(current -> key > x)
        {
            successor = current;
            current = current -> left;
        }
        else
        {
            current = current -> right;
        }
    }
    return successor;
}

Node * Binary_Tree:: prev(int x)
{
    Node *current = this -> root , *successor = NULL;
    while(current != NULL)
    {
        if(current -> key < x)
        {
            successor = current;
            current = current -> right;
        }
        else
        {
            current = current -> left;
        }
    }
    return successor;
}

Node * Binary_Tree:: exists(int x)
{
    Node *current = this -> root;
    while(current != NULL && current -> key != x)
    {
        current = current -> key > x ? current -> left : current -> right;
    }
    return current;
}

Node * Binary_Tree:: element_insert(Node *x , int z)
{
    if(x == NULL)
    {
        x = new Node;
        x -> parent = NULL;
        x -> left = NULL;
        x -> right = NULL;
        x -> key = z;
        return x;
    }
    else
    {
        if(z < x -> key)
        {
            x -> left = element_insert(x -> left , z);
        }
        if(z > x -> key)
        {
            x -> right = element_insert(x -> right , z);
        }
    }
    return x;
}

Node * Binary_Tree:: element_delete(Node *x , int z)
{
    if(x == NULL)
    {
        return x;
    }
    if(z < x -> key)
    {
        x -> left = element_delete(x -> left , z);
    }
    else
    {
        if(z > x -> key)
        {
            x -> right = element_delete(x -> right , z);
        }
        else
        {
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

void Binary_Tree:: tree_delete(Node *leaf)
{
    if(leaf != NULL)
    {
        tree_delete(leaf -> left);
        tree_delete(leaf -> right);
        delete leaf;
    }
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("bstsimple.in");
    fout.open("bstsimple.out");
    Binary_Tree A;
    string str;
    int x;
    Node *result = new Node;
    while(fin >> str)
    {
        fin >> x;
        if(str == "insert")
        {
            A.set_root(A.element_insert(A.get_root() , x));
        }
        if(str == "delete")
        {
            A.set_root(A.element_delete(A.get_root() , x));
        }
        if(str == "next")
        {
            result = A.next(x);
            if(result == NULL)
            {
                fout << "none" << endl;
            }
            else
            {
                fout << result -> key << endl;
            }
        }
        if(str == "prev")
        {
            result = A.prev(x);
            if(result == NULL)
            {
                fout << "none" << endl;
            }
            else
            {
                fout << result -> key << endl;
            }
        }
        if(str == "exists")
        {
            result = A.exists(x);
            fout << (result ? "true" : "false") << endl;
        }
    }
    fin.close();
    fout.close();
    return 0;
}
