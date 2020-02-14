#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next = NULL;
};

struct stack
{
    Node* head = NULL;
    stack(int x)
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
        head = head -> next;
        int a = temp -> data;
        delete temp;
        return a;
    }

    ~stack()
    {
        while (head != NULL)
        {
            Node* temp = head;
            head = head -> next;
            delete temp;
        }
    }
};

int main()
{


    return 0;
}
