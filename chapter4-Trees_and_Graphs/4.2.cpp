#include <vector>
#include "tree.h"


/* gieven a sorted array (ascending order), create a binary search tree with minimal height */
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
    vector<int> array{0, 1, 2, 3, 4, 5, 6, 7};

    printTree(createMinimalBST(array, 0, array.size() - 1));

    return 0;
}
