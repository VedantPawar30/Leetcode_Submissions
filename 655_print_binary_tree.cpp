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
    int height(TreeNode* root){
        if(!root) return -1;

        int lh=height(root->left);
        int rh=height(root->right);
        return 1+max(lh,rh);
    }
    void helper(TreeNode* root, vector<vector<string>> &ans,int r,int c,int h){
        if(!root->left && !root->right) return;
        int power = h-r-1;

        if(root->left){
            int leftRow = r+1;
            int leftCol = c - (1<<power);
            ans[leftRow][leftCol] = to_string(root->left->val);
            helper(root->left,ans,leftRow,leftCol,h);
        }

        if(root->right){
            int rightRow = r+1;
            int rightCol = c+(1<<power);
            
            ans[rightRow][rightCol] = to_string(root->right->val);

            
            helper(root->right,ans,rightRow,rightCol,h);
        }
        
        


    }
    vector<vector<string>> printTree(TreeNode* root) {
        int m = height(root)+1;
        int n= (1<<m) - 1;
        vector<vector<string>> ans(m,vector<string>(n,""));
        ans[0][(n-1)/2] = to_string(root->val);
        int r=0;
        int c= (n-1)/2;
        helper(root,ans, r, c,m-1);
        return ans;
    }
};