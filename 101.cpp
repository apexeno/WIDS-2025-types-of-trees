#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        // Case 1: Both nodes are missing (nullptr). 
        // A ghost matches a ghost! -> True
        if (t1 == nullptr && t2 == nullptr) return true;

        // Case 2: Only one node is missing.
        // A ghost does NOT match a real node -> False
        if (t1 == nullptr || t2 == nullptr) return false;

        // Case 3: Both nodes exist.
        // They are mirrors ONLY if:
        // A. Their values are the same
        // B. The outer branches match (Left vs Right)
        // C. The inner branches match (Right vs Left)
        return (t1->val == t2->val)
            && isMirror(t1->left, t2->right)
            && isMirror(t1->right, t2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        
        // Start comparing the left branch against the right branch
        return isMirror(root->left, root->right);
    }
};

