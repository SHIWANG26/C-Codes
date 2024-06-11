#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertAtHead(Node *&head,Node* tail, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    if (head==NULL)
    {
        tail = newNode;
    }
    
    head = newNode;
}
void insertAtTail(Node* &head, Node *&tail, int data)
{
    Node *newNode = new Node;
    if (tail == NULL)
    {
        tail = newNode;
    }
    else
        tail->next = newNode;
    if (head == NULL)
    {
        head = newNode;
    }
    tail = newNode;
}
void print_LL(Node *&head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    // Node* first = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30);
    // Node* fourth = new Node(40);
    // Node* fifth = new Node(50);
    // first-> next = second;
    // second-> next = third;
    // third-> next = fourth;
    // fourth->next = fifth;
    Node *head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail, 10);
    insertAtHead(head,tail, 20);
    insertAtHead(head,tail, 30);
    insertAtHead(head,tail, 40);
    insertAtHead(head,tail, 50);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);
    cout << "Printing the LL\n";
    print_LL(head);

    return 0;
}
