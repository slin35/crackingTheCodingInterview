#include "tree.h"

/* in-order successor: find the next node in in-order traversal order (assume there's parent)
 * 
 * 2 situations:
 *  - has right child
 *      - go to the right once and then as left as possible
 *  - don't have right child
 *      - go up till the node is the left child of the parent
*/
TreeNode* inorderSucessor(TreeNode* node) {
    if (node->right) {
            node = node->right;
            while (node->left) {
                node = node->left;
            }
            
            return node;
        }
        
        while (node->parent && node == node->parent->right) {
            node = node->parent;
        }
        
        return node->parent;
}

int main() {
    cout << inorderSucessor(new TreeNode(3)) << endl;
    return 0;
}