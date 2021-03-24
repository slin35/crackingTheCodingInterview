#include <iostream>
#include "node.h"

using namespace std;

/* delete middle node (not the first and last node) */
void deleteMidNode(ListNode* head) {
    if (head->next == nullptr || head->next->next == nullptr)
        return;

    ListNode* start = head, *end = head->next, *prev = nullptr;

    while (end->next != nullptr) {
        
        if (end->next->next) {
            end = end->next->next;
        }
        else {
            end = end->next;
        }

        prev = start;
        start = start->next;
    }

    /* delete middle node */
    prev->next = start->next;
}

int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 =  new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(6);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    ListNode *head = node1;

    deleteMidNode(head);
    printNode(head);

    return 0;
}
