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
    pair<int,int> helper(TreeNode* root, int &cnt){
        if(!root->left && !root->right){
            cnt++;
            return {root->val,1};
        }
        pair<int,int> leftPair;
        pair<int,int> rightPair;
        int leftSum=0;
        int leftCnt = 0;
        int rightSum =0;
        int rightCnt=0;
        if(root->left){
            leftPair = helper(root->left,cnt);
            leftSum = leftPair.first;
            leftCnt = leftPair.second;
        }

        if(root->right){
            rightPair = helper(root->right,cnt);
            rightSum = rightPair.first;
            rightCnt = rightPair.second;
        }

        int currSum = root->val + leftSum + rightSum;
        int currCnt = 1 + leftCnt + rightCnt;

        int avg=currSum/currCnt;
        if(avg == root->val) cnt++;

        return {currSum,currCnt};
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
        helper(root,cnt);
        return cnt;
    }
};