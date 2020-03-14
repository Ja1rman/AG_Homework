#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next = NULL;
};

struct list
{
    Node* head = NULL;

    list (int x)
    {
        head = new Node;
        head -> data = x;
    }

    void push(int a)
    {
        if (head == NULL)
        {
            head = new Node;
            head -> data = a;
            return;
        }

        Node* temp = new Node;
        temp -> data = a;
        head = temp;
    }

    int pop()
    {
        Node* temp = head;
        while (temp -> next -> next != NULL)
            temp = temp -> next;

        int x = temp -> next -> data;
        delete temp -> next;
        temp -> next = NULL;
        return x;
    }

    ~list()
    {
        Node* temp = head;
        head = head -> next;
        delete temp;
    }
};



int main()
{
    list test(1);
    test.push(7);
    test.push(8);
    test.push(9);

    int x = test.pop();
    cout << x;

    return 0;
}
