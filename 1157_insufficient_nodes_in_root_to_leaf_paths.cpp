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
    bool helper(TreeNode* root, int limit,int currSum){
        if(!root->left && !root->right){
            currSum += root->val;
            if(currSum<limit) return false;
            return true;
        }

        bool leftSum =false;
        bool rightSum = false;
        if(root->left){
            leftSum = helper(root->left,limit,currSum + root->val);
        }

        if(root->right){
            rightSum = helper(root->right, limit, currSum + root->val);
        }

        
        
        if(!leftSum && !rightSum){
            root->left = NULL;
            root->right = NULL;
            return false;
        }

        else if(!leftSum && rightSum){
            root->left = NULL;
            return true;

        }

        else if(leftSum && !rightSum){
            root->right = NULL;
            return true;
        }

        return true;


    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        int currSum =0;
        bool a=helper(root,limit,currSum);
        if(!a) return NULL;
        return root;
    }
};