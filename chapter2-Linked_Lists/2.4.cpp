#include <iostream>
#include "node.h"

using namespace std;

/* partition around a value x such that
 * all nodes < x come before all nodes >= x
*/
ListNode* partition(ListNode *head, int x) {
    ListNode *cur = head, *curHead = head, *tail = head;

    while (cur != nullptr) {
        ListNode *next = cur->next;

        if (cur->val < x) {        // if cur < x,
            cur->next = curHead;   // insert at curhead
            curHead = cur;         // cur becomes the new curhead
        }
        else {                     // if cur >= x,
            tail->next = cur;      // insert at tail
            tail = cur;            // cur becomes the new tail
        }

        cur = next;
    }

    tail->next = nullptr;
    return curHead;
}

int main() {
    ListNode *node1 = new ListNode(3);
    ListNode *node2 =  new ListNode(5);
    ListNode *node3 = new ListNode(8);
    ListNode *node4 = new ListNode(5);
    ListNode *node5 = new ListNode(10);
    ListNode *node6 = new ListNode(2);
    ListNode *node7 = new ListNode(1);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;

    ListNode *head = node1;

    printNode(partition(head, 5));
    return 0;
}