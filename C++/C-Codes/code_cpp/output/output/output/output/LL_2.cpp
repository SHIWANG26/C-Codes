#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void print(Node *&head)
{
    Node *temp = head;
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int getLen(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != 0)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
void insertAtHead(Node *&head, Node *&tail, int data)
{
    // LL is empty
    if (head == 0)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    // LL is not empty
    else
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    Node *head = first;
    Node *tail = third;

    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    print(first);

    insertAtHead(head, tail, 40);
    
    print(first);

    return 0;
}
