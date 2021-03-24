#include <iostream>
#include <cassert>
#include "node.h"

using namespace std;

/* reverse without clone */
ListNode* reverse(ListNode* head) {
    ListNode* cur = head, *prev = nullptr, *next = nullptr;

    while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

/* reverse and clone */
ListNode* reverse2(ListNode *head) {
    ListNode *newHead = nullptr;

    while (head) {
        ListNode *newNode = new ListNode(head->val);
        newNode->next = newHead;
        newHead = newNode;
        head = head->next;
    }

    return newHead;
}
 

/* check if the linked list is a palindrome 
 * solution1: reverse thhe linked list the compare
*/
bool isPalindrome(ListNode* head) {

    return *reverse2(head) == *head;
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

    assert(isPalindrome(node1) == false);
    assert(isPalindrome(node5) == true);
    assert(isPalindrome(node7) == true);

    return 0;
}