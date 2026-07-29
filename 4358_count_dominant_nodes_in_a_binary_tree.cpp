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
    int helper(TreeNode* root,int &cnt){
        if(!root) return 0;
        if(!root->left && !root->right){
            cnt++;
            return root->val;
        }

        int leftS =helper(root->left,cnt);
        int rightS = helper(root->right,cnt);
        int maxi = max(leftS,rightS);
        if(root->val >=maxi){
            cnt++;
            return root->val;
        }
        return maxi;

    }
    int countDominantNodes(TreeNode* root) {
        int cnt=0;
        int t=helper(root,cnt);
        return cnt;
    }
};