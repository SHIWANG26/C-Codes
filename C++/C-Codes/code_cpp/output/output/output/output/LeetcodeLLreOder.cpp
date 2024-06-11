#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return;
        }
        
        // Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse the second half of the linked list
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        slow->next = nullptr; // Set the next pointer of the last node of the first half to nullptr
        
        // Merge the first half and the reversed second half alternately
        ListNode* p1 = head;
        ListNode* p2 = prev;
        while (p1 && p2) {
            ListNode* next1 = p1->next;
            ListNode* next2 = p2->next;
            p1->next = p2;
            p2->next = next1;
            p1 = next1;
            p2 = next2;
        }
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    sol.reorderList(head);

    cout << "Reordered List: ";
    printList(head);

    return 0;
}
