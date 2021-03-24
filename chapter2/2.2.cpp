#include <iostream>
#include "node.h"

using namespace std;

/* get kth to last element 
 * recursion: O(n) space
*/
ListNode* getKthToLast(ListNode* head, int k, int& i) {
    if (head == nullptr)
        return nullptr;
    ListNode* node = getKthToLast(head->next, k, i);
    i++;
    if (i == k)
        return head;
    return node;
}

/* two ptrs: O(1) space */
ListNode* getKthToLast(ListNode* head, int k) {
    ListNode* kth = head;
    ListNode* cur = head;

    while (k > 0) {
        cur = cur->next;
        k--;
    }

    while (cur != nullptr) {
        kth = kth->next;
        cur = cur->next;
    }

    return kth;
}

int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 =  new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    ListNode *head = node1;
    int i = 0;

    cout << getKthToLast(head, 3, i)->val << endl;
    cout << getKthToLast(head, 3)->val << endl;
    
    return 0;
}