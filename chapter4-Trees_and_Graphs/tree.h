#pragma once

#include <iostream>
#define COUNT 5

using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    bool visited;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode() : val(0), left(nullptr), right(nullptr), visited(false) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), visited(false), parent(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void printTree(TreeNode* root, int space = 0) {
    if (root == nullptr)
        return;
    space += COUNT;
    printTree(root->right, space);
    cout << endl;
    for (int i = COUNT; i < space; i++) {
        cout << " "; 
    }
    cout << root->val << endl;
    printTree(root->left, space);
}
