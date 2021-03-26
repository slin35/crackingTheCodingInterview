#include <cassert>
#include <climits>
#include "tree.h"

/* check if a binary tree is a balanced search tree */
bool isBST(TreeNode* root) {
    if (root == nullptr)
        return true;

    int leftV = root->left ? root->left->val : INT_MIN;
    int rightV = root->right ? root->right->val : INT_MAX;

    return root->val > leftV && root->val <= rightV && isBST(root->left) && isBST(root->right);
}

int main() {
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(5);
    tree->right = new TreeNode(6);
    tree->left->left = new TreeNode(7);
    tree->left->left->left = new TreeNode(8);

    TreeNode* tree2 = new TreeNode(3);
    tree2->left = new TreeNode(0);
    tree2->right = new TreeNode(6);
    tree2->left->right = new TreeNode(2);

    assert(isBST(tree) == false);
    assert(isBST(tree2) == true);

    return 0;
}