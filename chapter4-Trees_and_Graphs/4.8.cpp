#include "tree.h"


/* find the first common ancestor 
 * solution 1: 
 * assuminng there's link to the parent
 * move the deeper node up the difference in length with the shallow node
 * traverse together to find the parent
 * time: O(depth)
*/
TreeNode* findFCA(TreeNode* tree, TreeNode* node1, TreeNode*node2) {
    int diff = height(node1) - height(node2);
    int cnt = abs(diff);

    if (diff < 0) {
        while (cnt >= 0 && node2) {
            node2 = node2->parent;
            cnt--;
        }
    }
    else {
        while (cnt >= 0 && node1) {
            node1 = node1->parent;
            cnt--;
        }
    }

    while (node1 != node2 && node1 && node2) {
        node1 = node1->parent;
        node2 = node2->parent;
    }

    return node1 == nullptr || node2 == nullptr ? nullptr : node1;
}

/*
 * solution 2: without parent
*/
TreeNode* findFCA2(TreeNode* tree, TreeNode* node1, TreeNode*node2) {
    if (!existed(tree, node1) || !existed(tree, node2))
        return nullptr;

    bool node1OnLeft = existed(tree->left, node1);
    bool node2OnLeft = existed(tree->left, node2);

    if (node1OnLeft != node2OnLeft)    // if both on different side, return the root node
        return tree;

    if (node1OnLeft) {        // if on the left subtree, go to the left
        return findFCA2(tree->left, node1, node2);
    }

    return findFCA2(tree->right, node1, node2);     // else go to the right
}

bool existed(TreeNode* tree, TreeNode* node) {
    if (tree == nullptr)
        return false;
    if (tree == node)
        return true;
    return existed(tree->left, node) || existed(tree->right, node);
}



int height(TreeNode* tree) {
    if (tree == nullptr)
        return 0;

    return max(height(tree->left), height(tree->right)) + 1;
}


int main() {
    
    return 0;
}