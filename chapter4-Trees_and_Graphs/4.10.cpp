#include "tree.h"


bool isIdentical(TreeNode* tree1, TreeNode* tree2) {
    if (tree1 == nullptr && tree2 == nullptr)
        return true;
    if (tree1 == nullptr || tree2 == nullptr)
        return false;

    return tree1->val == tree2->val && isIdentical(tree1->left, tree2->left) && isIdentical(tree1->right, tree2->right);
}

/* check subtree: 
 * T1, T2 are binary trees in which T1 is much larger than T2, determine if T2 is a subtree of T1
*/
bool isSubtree(TreeNode* tree1, TreeNode* tree2) {
    if (tree1 == nullptr && tree2 == nullptr)
        return true;
    if (tree1 == nullptr || tree2 == nullptr)
        return false;
    if (tree1->val == tree2->val) {
        return isIdentical(tree1, tree2);
    }

    return isSubtree(tree1->left, tree2) || isSubtree(tree1->right, tree2);
}

int main() {
    TreeNode* tree2 = new TreeNode(10);
    tree2->left = new TreeNode(5);
    tree2->left->left = new TreeNode(2);
    tree2->left->right = new TreeNode(4);

    TreeNode* tree = new TreeNode(5);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(4);
    
    TreeNode* tree3 = new TreeNode(11);
    cout << isSubtree(tree2, tree) << endl;
    cout << isSubtree(tree2->left, tree) << endl;
    cout << isSubtree(tree2, tree3) << endl;

    return 0;
}