#include <iostream>
#include "node.h"

using namespace std;

/* sum lists
 * numbers are represented in a linked list with digits stored in reverse order
 * ex: 617 + 295 = 912 equivalent to 7->1->6 + 5->9->2 = 2->1->9
*/
ListNode* sumLists(ListNode* l1, ListNode* l2) {
    ListNode* answer = nullptr, *cur = nullptr;
    int carry = 0, sum = 0;

    while (l1 != nullptr || l2 != nullptr) {
        int val1 = (l1 == nullptr) ? 0 : l1->val;
        int val2 = (l2 == nullptr) ? 0 : l2->val;
        sum = val1 + val2 + carry;
        carry = sum / 10;
        ListNode* newNode = new ListNode(sum%10);

        if (answer) {
            cur->next = newNode;
            cur = cur->next;
        }
        else {
            cur = newNode;
            answer = cur;
        }

        if (l1 != nullptr)
            l1 = l1->next;
        if (l2 != nullptr)
            l2 = l2->next;
    }


    if (carry != 0) {
        cur->next = new ListNode(carry);
    }

    return answer;
}

int main() {
    ListNode *node1 = new ListNode(7);
    ListNode *node2 =  new ListNode(1);
    ListNode *node3 = new ListNode(6);
    ListNode *node4 = new ListNode(5);
    ListNode *node5 = new ListNode(9);
    ListNode *node6 = new ListNode(2);
    
    node1->next = node2;
    node2->next = node3;

    node4->next = node5;
    node5->next = node6;

    ListNode *l1 = node1;
    ListNode *l2 = node4;

    printNode(sumLists(l1, l2));

    return 0;
}