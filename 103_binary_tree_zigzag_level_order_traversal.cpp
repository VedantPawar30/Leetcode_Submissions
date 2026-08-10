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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool turn =0;
        while(!q.empty()){
            int n=q.size();
            vector<int> temp;

            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(turn){
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }else{
                ans.push_back(temp);
            }

            turn = !turn;
        }

        return ans;
    }
};