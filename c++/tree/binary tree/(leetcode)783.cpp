/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int prev_val = -10001;
    int answer = 10001;
    void DFS(TreeNode* node){
        if(node->left) DFS(node->left);
        
        answer = min(answer, abs(node->val-prev_val));
        prev_val = node->val;
        
        if(node->right) DFS(node->right);
        
        return;
    }
    int minDiffInBST(TreeNode* root) {
        DFS(root);
        cout << answer << endl;
        return answer;
    }
};