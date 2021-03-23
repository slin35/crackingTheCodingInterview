#pragma once
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void printNode(ListNode *head) {
    ListNode *cur = head;
    while (cur != nullptr) {
        std::cout << cur->val << std::endl;
        cur = cur->next;
    }
}