#pragma once
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    bool operator==(ListNode& list2){
        ListNode* node1 = this;
        ListNode* node2= &list2;

        while (node1 && node2) {
            if (node1->val != node2->val)
                return false;
            
            node1 = node1->next;
            node2 = node2->next;
        }
        
        return node1 == nullptr && node2 == nullptr;
    }
};


void printNode(ListNode *head) {
    ListNode *cur = head;
    while (cur != nullptr) {
        std::cout << cur->val << std::endl;
        cur = cur->next;
    }
}