#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* &head){
    if(head == NULL) {
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);
}

int getLength(Node* &head){
    Node* temp = head;
    int len = 0;
    do {
        len++;
        temp = temp->next;
    } while(temp != head);
    return len;
}


void insertAtHead(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        head->next = head;
        head->prev = tail;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    tail->next = head;
    head->prev = tail;
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        head->next = head;
        head->prev = tail;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    tail->next = head;
    head->prev = tail;
}
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 0);

    cout << "Circular Linked List: ";
    print(head);
    cout << endl;

    return 0;
}