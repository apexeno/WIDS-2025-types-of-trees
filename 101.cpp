#include <algorithm>
#include <cmath>
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
    // Helper function that returns the height of the tree if balanced, 
    // or -1 if it is unbalanced.
    int checkHeight(TreeNode* node) {
        // Base case: An empty tree has height 0 and is balanced.
        if (node == nullptr) {
            return 0;
        }

        // 1. Check Left Subtree
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1; // If left is unbalanced, propagate error

        // 2. Check Right Subtree
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; // If right is unbalanced, propagate error

        // 3. Check Current Node Balance
        if (abs(leftHeight - rightHeight) > 1) {
            return -1; // Current node is unbalanced
        }

        // 4. Return Height (Max of children + 1 for self)
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        // If checkHeight returns anything other than -1, it is balanced.
        return checkHeight(root) != -1;
    }
};
