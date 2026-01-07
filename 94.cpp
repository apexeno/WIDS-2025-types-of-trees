#include <vector>
using namespace std;

class Solution {
public:
    void traverse(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        
        // 1. Traverse Left
        traverse(node->left, result);
        
        // 2. Visit Root
        result.push_back(node->val);
        
        // 3. Traverse Right
        traverse(node->right, result);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
};