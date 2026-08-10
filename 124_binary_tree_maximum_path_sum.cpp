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
    int maxi = INT_MIN;
    int helper(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right){
            maxi = max(maxi,root->val);
            cout<<maxi<<endl;
            return root->val;
        }

        int leftSum = helper(root->left);
        int rightSum = helper(root->right);
        cout<<"Left Sum :"<<leftSum<<endl;
        cout<<"Right SUm :"<<rightSum<<endl;
        int currTurnSum = leftSum + rightSum + root->val;

        int currLeftBranchSum = leftSum + root->val;
        int currRightBranchSum = rightSum + root->val;

        maxi = max({maxi,currTurnSum, currLeftBranchSum,currRightBranchSum,root->val});
        cout<<maxi<<endl;
        return max({root->val, currLeftBranchSum,currRightBranchSum});
    }
    int maxPathSum(TreeNode* root) {
        int ans = helper(root);
        return maxi;

    }
};