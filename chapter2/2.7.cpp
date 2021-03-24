#include <iostream>
#include <cassert>
#include "node.h"

using namespace std;

/* find the intersection of two linked lists by reference not value */
ListNode* intersect(ListNode* l1, ListNode* l2) {
    ListNode *p1 = l1, *p2 = l2;

    while (p1 != p2) {
        p1 = (p1 == nullptr) ? l1 : p1->next;
        p2 = (p2 == nullptr) ? l2 : p2->next;
    }

    return p1;
}

bool isIntersect(ListNode* l1, ListNode* l2) {
    return intersect(l1, l2) != nullptr;
}


int main() {
    ListNode *node1 = new ListNode(3);
    ListNode *node2 =  new ListNode(5);
    ListNode *node3 = new ListNode(8);
    ListNode *node4 = new ListNode(5);
    ListNode *node5 = new ListNode(1);
    ListNode *node6 = new ListNode(2);
    ListNode *node7 = new ListNode(1);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;

    assert(isIntersect(node1, node5) == true);
    assert(isIntersect(node1, node7) == true);
    assert(isIntersect(node1, new ListNode(100)) == false);

    return 0;
}