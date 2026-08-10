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
    int search(vector<int> &inorder,int l,int r,int val){
        for(int i=l;i<=r;i++){
            if(inorder[i]==val) return i;
        }
        return -1;
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int &postIdx,int l,int r){
        if(l>r) return NULL;

        TreeNode* newNode = new TreeNode(postorder[postIdx]);
        int pos = search(inorder,l,r,postorder[postIdx]);
        postIdx--;
        newNode->right = helper(inorder,postorder,postIdx,pos+1,r);
         newNode->left = helper(inorder,postorder,postIdx,l,pos-1);

        return newNode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int postIdx = postorder.size()-1;
        int l=0;
        int r=n-1;

        return helper(inorder,postorder,postIdx,l,r);
    }
};