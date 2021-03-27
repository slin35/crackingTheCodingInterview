#include <vector>
#include "tree.h"

/* BST Sequences: print out all possible arrays that could form the BST 
 * insight 1: 
 *  after the root node is inserted, 
 *  the position of its immediate children is determined by value, not insertion order
 *
 * insight 2:
 *  by combining the insertion order of sub-trees,
 *  a solution is found for nodes furthur up.
 *  Q: the question is how to combine it?
 *  A: root must inserted before its children to keep the ordering in 2 sub-trees,
 *      then prepend the root in front of each ordering.
 * the process of combining the lists while mainteining order is called weaving:
 * prefix[] + subtree1[] + subtree2[]    <- ordering
 * when one of the subtrees is empty, one ordering is generated
*/
void weave(vector<int>& prefix, vector<int>& subtree1, vector<int>& subtree2, vector<vector<int>>& res) {
    if (subtree1.size() == 0 || subtree2.empty() == true) {
        vector<int> des;
        copy(prefix.begin(), prefix.end(), back_inserter(des));
        copy(subtree1.begin(), subtree1.end(), back_inserter(des));
        copy(subtree2.begin(), subtree2.end(), back_inserter(des));
        res.push_back(des);
        return;
    }

    // remove left most item from subtree1
    int headFirst = subtree1.front();
    subtree1.erase(subtree1.begin());
    prefix.push_back(headFirst);
    weave(prefix, subtree1, subtree2, res);
    prefix.pop_back();
    subtree1.insert(subtree1.begin(), headFirst);

    // remove left most item from subtree2
    int headSecond = subtree2.front();
    subtree2.erase(subtree2.begin());
    prefix.push_back(headSecond);
    weave(prefix, subtree1, subtree2, res);
    prefix.pop_back();
    subtree2.insert(subtree2.begin(), headSecond);
}

vector<vector<int>> getBSTSequences(TreeNode* node) {
    vector<vector<int>> res;
    vector<int> prefix;

    if (node == nullptr) {
        res.push_back(vector<int>());
        return res;
    }

    prefix.push_back(node->val);

    vector<vector<int>> leftSequences = getBSTSequences(node->left);
    vector<vector<int>> rightSequences = getBSTSequences(node->right);

    for (auto left : leftSequences) {
        for (auto right : rightSequences) {
            vector<vector<int>> weaved;
            weave(prefix, left, right, weaved);
            res.insert(res.end(), weaved.begin(), weaved.end());
        }
    }

    return res;
}

void printVector(vector<vector<int>> res) {
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    TreeNode* tree = new TreeNode(2);
    tree->left = new TreeNode(1);
    tree->right = new TreeNode(3);

    TreeNode* tree2 = new TreeNode(10);
    tree2->left = new TreeNode(5);
    tree2->left->left = new TreeNode(2);
    tree2->left->right = new TreeNode(4);
    tree2->right = new TreeNode(20);
    tree2->right->right = new TreeNode(30);

    vector<vector<int>> res = getBSTSequences(tree);
    vector<vector<int>> res2 = getBSTSequences(tree2);

    printVector(res);
    cout << endl;
    printVector(res2);

    return 0;
}