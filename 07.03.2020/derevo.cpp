#include <iostream>
#include <queue>
#include <algorithm>

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
    void del (Node* t)
    {
        if (t -> left) del(t -> left);
        if (t -> right) del(t -> right);
        delete t;
    }
};

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
    int a = t -> data;
    cout << a;
    
    if (t -> right != NULL)
        print(t -> right);
}

bool search (Node* t, int x)
{
    if (t -> data > x)
        if (search(t = t -> left, x)) return 1;
    else if (t -> data < x)
        if (search(t = t -> right, x)) return 1;
    else if (t -> data == x) return 1;
    
    return 0;
}

void add(Node* t, int x)
{
    while (t != NULL)
        if (x > t -> data) t = t -> right;
        else t = t -> left;
    t -> data = x;
}

int height(Node* root)
{
    if (root -> left == NULL) 
        if (root -> right == NULL) return 0;
        else return height(root -> right);
        
    if (root -> right == NULL) 
        if (root -> left == NULL) return 0;
        else return height(root -> left);
        
    return max(height(root -> left), height(root -> right));
}

void rotateRight(Node* root)
{
    Node* a = ...;
    Node* b = a -> left;
    Node* c = b -> right;
    &b ...;
    a -> left = c;
    b -> right = a;
}

void rotateLeft(Node* root)
{
    Node* a = ...;
    Node* b = a -> right;
    Node* c = b -> left;
    &b ...;
    a -> right = c;
    b -> left = a;
}

void bigRotateLeft(Node* root)
{
    Node* a = ...;
    Node* b = a -> right;
    Node* c = b -> left;
    Node* m = c -> left;
    Node* n = c -> right;
    &c ...;
    c -> left = a;
    a -> right = m;
    c -> right = b;
    b -> left = n;
}

void bigRotateRight(Node* root)
{
    Node* a = ...;
    Node* b = a -> left;
    Node* c = b -> right;
    Node* m = c -> left;
    Node* n = c -> right;
    &c ...;
    c -> right = a;
    a -> left = n;
    c -> left = b;
    b -> right = m;
}

int main()
{
    

    return 0;
}
