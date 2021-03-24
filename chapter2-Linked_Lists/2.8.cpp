#include <iostream>
#include "node.h"

using namespace std;

/* loop detection
 * returning the beginning of theh circular loop
 * Solution: Floyd's tortoise and hare
*/
ListNode *getLoop(ListNode *head) {
    ListNode *hare = head, *tortoise = head;
    
    while (hare && hare->next) {
        tortoise = tortoise->next;
        hare = hare->next->next;
        
        if (hare == tortoise) {
            hare = head;
            while (hare != tortoise) {
                hare = hare->next;
                tortoise = tortoise->next;
            }
            
            return tortoise;
        }
    }
    
    return nullptr;
}


int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 =  new ListNode(2);
    ListNode *node3 = new ListNode(3);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node2;

    cout << getLoop(node1)->val << endl;
    
    return 0;
}