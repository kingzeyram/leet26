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
    /**
     * DFS helper
     * @return pair:
     *   first  -> maximum depth from this node downward
     *   second -> subtree root that contains all deepest nodes
     */
    pair<int, TreeNode*> dfs(TreeNode* root) {
        // Base case: empty node
        if (!root) {
            return {0, nullptr};
        }

        // Recursively process left and right subtrees
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // Case 1: left subtree is deeper
        if (left.first > right.first) {
            return {
                left.first + 1,  // increase depth
                left.second      // propagate left subtree root
            };
        }

        // Case 2: right subtree is deeper
        if (right.first > left.first) {
            return {
                right.first + 1, // increase depth
                right.second     // propagate right subtree root
            };
        }

        // Case 3: both subtrees have the same depth
        // Current node becomes LCA of deepest nodes
        return {
            left.first + 1,  // depth increases by 1
            root             // current node is the answer
        };
    }

    /**
     * Main function
     */
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
