// 1339. Maximum Product of Splitted Binary Tree
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

// Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

// Note that you need to maximize the answer before taking the mod and not after taking it.

 

// Example 1:


// Input: root = [1,2,3,4,5,6]
// Output: 110
// Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
// Example 2:


// Input: root = [1,null,2,3,4,null,null,5,6]
// Output: 90
// Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)
 

// Constraints:

// The number of nodes in the tree is in the range [2, 5 * 104].
// 1 <= Node.val <= 104

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    long long totalSum = 0;
    long long maxProductVal = 0;
    const int MOD = 1e9 + 7;

    // First DFS: calculate total sum of all nodes
    long long getTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val 
             + getTotalSum(root->left) 
             + getTotalSum(root->right);
    }

    // Second DFS: compute subtree sums and update max product
    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long leftSum = dfs(root->left);
        long long rightSum = dfs(root->right);

        long long subTreeSum = root->val + leftSum + rightSum;

        // Consider splitting above this subtree
        long long product = subTreeSum * (totalSum - subTreeSum);
        maxProductVal = max(maxProductVal, product);

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root); // Step 1
        dfs(root);                    // Step 2
        return maxProductVal % MOD;
    }
};

int main() {
    /*
        Example:
        Tree: [1,2,3,4,5,6]

              1
             / \
            2   3
           / \   \
          4   5   6
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;
    cout << "Maximum Product: " << sol.maxProduct(root) << endl;

    return 0;
}
