#include <vector>
#include <climits>
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
    int currVal = 0;
    int currCount = 0;
    int maxCount = 0;
    vector<int> modes;

    void handleValue(int val) {
        // 1. Update the count for the current value
        if (val == currVal) {
            currCount++;
        } else {
            currCount = 1;
            currVal = val;
        }

        // 2. Compare with the maximum frequency found so far
        if (currCount > maxCount) {
            // Found a new winner! Clear old modes and start fresh.
            maxCount = currCount;
            modes.clear();
            modes.push_back(val);
        } else if (currCount == maxCount) {
            // Found a tie! Add this value to the list.
            modes.push_back(val);
        }
    }

    void inorder(TreeNode* node) {
        if (node == nullptr) return;

        // Traverse Left
        inorder(node->left);

        // Process Node
        handleValue(node->val);

        // Traverse Right
        inorder(node->right);
    }

    vector<int> findMode(TreeNode* root) {
        // Reset variables for safety (in case object is reused)
        currVal = INT_MIN; 
        currCount = 0;
        maxCount = 0;
        modes.clear();
        
        inorder(root);
        return modes;
    }
};