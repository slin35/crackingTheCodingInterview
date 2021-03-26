#include <cassert>
#include "tree.h"

int height(TreeNode* root, bool& res) {
    if (root == nullptr) {
        return 0;
    }
    
    int left = height(root->left, res);
    int right = height(root->right, res);
    
    if (abs(left - right) > 1) {
        res = false;
        return -1;
    }
    
    return max(left, right) + 1;
}

/* check if a binary tree is balanced
 * the height of two subtrees of any node diff by <= 1
*/
bool isBalanced(TreeNode* root) {
    if (root == nullptr)
        return true;

    bool res = true;
    height(root, res);
    
    return res;
}



int main() {
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(5);
    tree->right = new TreeNode(6);
    tree->left->left = new TreeNode(7);
    tree->left->left->left = new TreeNode(8);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(5);
    tree2->right = new TreeNode(6);
    tree2->left->right = new TreeNode(7);

    assert(isBalanced(tree) == false);
    assert(isBalanced(tree2) == true);

    return 0;
}