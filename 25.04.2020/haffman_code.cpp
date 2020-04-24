#include <bits/stdc++.h>

using namespace std;

struct Node
{
    string name = '';
    int data = 0;
    Node* left = NULL;
    Node* right = NULL;
};

struct haf_code
{
    Node* root = NULL;

    haf_code (int x, string y)
    {
        root = new Node;
        root -> data = x;
        root -> name = y;
    }

    ~haf_code()
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
/*
void print (Node* t)
{
    if (t -> left != NULL)
        print(t -> left);

    int a = t -> data;
    cout << a;

    if (t -> right != NULL)
        print(t -> right);
}
*/
void add(Node* t, int x)
{
    if (t -> right != NULL || t -> left != NULL)
    {
        t -> data += x;
        t -> name += y;
        if (t -> right == NULL && t -> left == NULL)
        {
            t -> left -> data = x;
            t -> left -> name = y;
        }
        else if (t -> right != NULL)
        {
            if(t -> right -> data > x)
            {
                t -> left -> data = x;
                t -> left -> name = y;
            }
            else
            {
                t -> left -> data = t -> right -> data;
                t -> left -> name = t -> right -> name;
                t -> right -> data = x;
                t -> right -> name = y;
            }
        }
        else
        {
            if(t -> left -> data < x)
            {
                t -> right -> data = x;
                t -> right -> name = y;
            }
            else
            {
                t -> right -> data = t -> left -> data;
                t -> right -> name = t -> left -> name;
                t -> left -> data = x;
                t -> left -> name = y;
            }
        }
    }
    else
    {
        if (t -> data > x)
        {
            t -> right = t;
            t -> left -> data = x;
            t -> left -> name = y;
            t -> data = x + t -> right -> data;
            t -> name = y + t -> right -> name;
        }
        else
        {
            t -> left = t;
            t -> right -> data = x;
            t -> right -> name = y;
            t -> data = x + t -> left -> data;
            t -> name = y + t -> left -> name;
        }
    }
}

bool cmp (pair<int, char> p1, pair<int, char> p2)
{
    return p1.first < p2.first;
}

int main()
{
    setlocale(LC_ALL, "rus");

    map <char, int> chars;

    char str[500];
    cout << "Введите текст для кодирования:" << endl;
    gets(str);

    for(unsigned int i = 0; i < strlen(str); i++)
        chars[str[i]]++;

    map <char, int>::iterator begin, at, end;
    begin = chars.begin();
    end = chars.end();

    int size = chars.size();
    vector <pair<int, char> > arr(size);

    for(at = begin; at != end; at++)
    {
        int a = at -> second;
        char b = at -> first;
        arr.push_back(make_pair(a,b));
    }

    sort(arr.begin(), arr.end(), cmp);

    arr.erase(arr.begin(), arr.begin() + size);

    haf_code gog;


    for (vector <pair<int, char> >::iterator it = arr.begin(); it != arr.end(); it++)
         gog.add(it -> first, it -> second)
    return 0;
}
