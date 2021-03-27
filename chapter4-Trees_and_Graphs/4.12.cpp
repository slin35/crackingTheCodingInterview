#include <cassert>
#include <map>
#include "tree.h"

void traverse(TreeNode* root, int sum, int curSum, int& cnt, map<int, int>& sequence_map) {
    if (root == nullptr)
        return;
    
    curSum += root->val;
    if (curSum == sum)
        cnt++;
    
    if (sequence_map.find(curSum - sum) != sequence_map.end()) {
        cnt += sequence_map[curSum - sum];
    }
    
    if (sequence_map.find(curSum) != sequence_map.end()) {
        sequence_map[curSum] += 1;
    }
    else {
        sequence_map.emplace(curSum, 1);
    }
    
    traverse(root->left, sum, curSum, cnt, sequence_map);
    traverse(root->right, sum, curSum, cnt, sequence_map);
    
    sequence_map[curSum] -= 1;
    
}

/* path sum (leetcode 437):
 * given a binary tree and a value, return the number of paths down the tree have a sum of that value
*/
int pathSum(TreeNode* root, int sum) {
    int cnt = 0;
    map<int, int> sequence_map;

    traverse(root, sum, 0, cnt, sequence_map);

    return cnt;
}



int main() {
    TreeNode* tree = new TreeNode(10);
    tree->left = new TreeNode(5);
    tree->left->left = new TreeNode(3);
    tree->left->right = new TreeNode(2);
    tree->left->left->left = new TreeNode(3);
    tree->left->left->right = new TreeNode(-2);
    tree->left->right->right = new TreeNode(1);
    tree->right = new TreeNode(-3);
    tree->right->right = new TreeNode(11);

    assert(pathSum(tree, 8) == 3);

    return 0;
}