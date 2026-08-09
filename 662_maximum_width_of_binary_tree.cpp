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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int maxWidth=1;
        while(!q.empty()){
            int n=q.size();
            int first=0;
            int last=0;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front().first;
                long long idx = q.front().second;
                q.pop();
                if(i==0) first =idx;
                if(i==n-1) last=idx;
                if(node->left) q.push({node->left, 1ll*2*idx+1});
                if(node->right) q.push({node->right, 1ll*2*idx+2});
            }

            maxWidth=max(maxWidth,last-first+1);
        }

        return maxWidth;
    }
};