class Solution {
public:
    void helper(int idx,int k,int n,vector<vector<int>> &ans,vector<int> &temp){
        if(k==0 && n==0){
            ans.push_back(temp);
            return;
        }
        
        if(n<0 || idx==10) return;
        

        temp.push_back(idx);
        helper(idx+1,k-1,n-idx,ans,temp);
        temp.pop_back();
        helper(idx+1,k,n,ans,temp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(1,k,n,ans,temp);
        return ans;
    }
};