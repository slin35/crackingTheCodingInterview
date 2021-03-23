#include <iostream>
#include <unordered_map>
#include "node.h"

using namespace std;

/* remove duplicates from unsorted list */
void removeDup(ListNode* head) {
    unordered_map<int, int> map;

    ListNode* cur = head, *prev = nullptr;

    while (cur != nullptr) {
        if (map.find(cur->val) == map.end()) {  // not found
            map.emplace(cur->val, 1);
            prev = cur;
        }
        else {  // remove the duplicate
            prev->next = cur->next;
            cur = prev;
        }
        cur = cur->next;
    }

}

int main() {
    ListNode *node1 = new ListNode(10);
    ListNode *node2 =  new ListNode(11);
    ListNode *node3 = new ListNode(10);
    ListNode *head = node3;
    node3->next = node2;
    node2->next = node1;

    removeDup(head);
    printNode(head);

    return 0;
}