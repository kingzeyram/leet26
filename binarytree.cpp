// Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

// Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

 

// Example 1:


// Input: root = [1,7,0,7,-8,null,null]
// Output: 2
// Explanation: 
// Level 1 sum = 1.
// Level 2 sum = 7 + 0 = 7.
// Level 3 sum = 7 + -8 = -1.
// So we return the level with the maximum sum which is level 2.
// Example 2:

// Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
// Output: 2
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -105 <= Node.val <= 105

#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        // Queue for BFS (level-order traversal)
        queue<TreeNode*> q;
        q.push(root);

        // Level counters
        int currentLevel = 1;   // Tracks current level number
        int maxLevel = 1;       // Level with the maximum sum

        // Initialize maxSum with root value (level 1)
        long long maxSum = root->val;

        // Continue traversal while nodes exist
        while (!q.empty()) {

            // Number of nodes at the current level
            int levelSize = q.size();

            // Sum of values at this level
            long long levelSum = 0;

            // Traverse all nodes in the current level
            for (int i = 0; i < levelSize; i++) {

                TreeNode* node = q.front();
                q.pop();

                // Add node value to current level sum
                levelSum += node->val;

                // Push left child if it exists
                if (node->left != nullptr) {
                    q.push(node->left);
                }

                // Push right child if it exists
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            // Update maximum sum and corresponding level
            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = currentLevel;
            }

            // Move to next level
            currentLevel++;
        }

        // Return the level with the maximum sum
        return maxLevel;
    }
};
