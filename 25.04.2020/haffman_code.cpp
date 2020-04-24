#include <bits/stdc++.h>

using namespace std;

struct Node
{
    string name;
    int data;
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
void add(Node* t, int x, string y)
{
    while (t != NULL)
        if (x > t -> data) t = t -> right;
        else t = t -> left;
    t -> data = x;
    t -> name = y;
}

bool cmp (pair<int, char> p1, pair<int, char> p2) {
  return p1.first > p2.first;
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
        int b = at -> second;
        char a = at -> first;
        arr.push_back(make_pair(b,a));
    }

    sort(arr.begin(), arr.end(), cmp);
    for (vector <pair<int, char> >::iterator it = arr.begin(); it != arr.end(); it++)
        cout << it -> first << '\t' << it -> second << endl;

    return 0;
}
