#include <vector>
#include <queue>
#include "tree.h"

/* create linked lists of all nodes at each depth */
void getLevelLinkedLists(TreeNode* root, vector<vector<int>>& res, int depth = 0) {
    if (root == nullptr)
        return;

    vector<int> list;
    if (res.size() == depth)
        res.push_back(list);

    res[depth].push_back(root->val);

    getLevelLinkedLists(root->left, res, depth + 1);
    getLevelLinkedLists(root->right, res, depth + 1);
    
}

TreeNode* createMinimalBST(vector<int> array, int start, int end) {
    if (end < start)
        return nullptr;

    int mid = start + (end - start) / 2;

    TreeNode* root = new TreeNode(array[mid]);

    root->left = createMinimalBST(array, start, mid - 1);
    root->right = createMinimalBST(array, mid + 1, end);

    return root;
}

int main() {
    vector<vector<int>> res;
    vector<int> array{0, 1, 2, 3, 4, 5, 6, 7};

    getLevelLinkedLists(createMinimalBST(array, 0, array.size() - 1), res);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}