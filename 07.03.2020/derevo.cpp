#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left = NULL;
    Node* right = NULL;
};

struct Tree
{
    Node* root = NULL;

    Tree (int x)
    {
        root = new Node;
        root -> data = x;
    }

    ~Tree()
    {
        del(root);
    }
};

void del (Node* t)
{
    if (t -> left) del(t -> left);
    if (t -> right) del(t -> right);
    delete t;
}

bool bfs (Node* t, int x)
{
    queue <Node*> A;
    A.push(t);
    while (!A.empty())
    {
        Node* p = A.front();
        A.pop();
        if (p -> data == x) return 1;
        if (p -> left) A.push(p -> left);
        if (p -> right) A.push(p -> right);
    }
    return 0;
}

void print (Node* t)
{
    if (t -> left != NULL)
        print(t -> left);
    else
    {
        int a = t -> data;
        cout << a;
    }

    if (t -> right != NULL)
        print(t -> right);
    else
    {
        int a = t -> data;
        cout << a;
    }
}

bool search (Node* t, int x)
{
    if (t -> data > x)
        if (search(t = t -> left)) return 1;
    else if (t -> data < x)
        if (search(t = t -> right)) return 1;
    else if (t -> data == x) return 1;

    return 0;
}

int main()
{


    return 0;
}
