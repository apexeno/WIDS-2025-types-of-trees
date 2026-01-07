#include <vector>
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
    // Helper function to construct the tree using indices
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        // Base Case: If left index crosses right, there are no elements left
        if (left > right) {
            return nullptr;
        }

        // 1. Find the middle element to be the root
        // Using (left + (right - left) / 2) prevents overflow for very large integers
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);

        // 2. Recursively build the left subtree using the left half
        node->left = buildBST(nums, left, mid - 1);

        // 3. Recursively build the right subtree using the right half
        node->right = buildBST(nums, mid + 1, right);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Start with the full range of the array
        return buildBST(nums, 0, nums.size() - 1);
    }
};
