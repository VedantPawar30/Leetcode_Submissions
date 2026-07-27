class Solution {
public:
    void helper(int idx,vector<int>& arr, int target, vector<vector<int>> &ans, vector<int> &temp){
        if(idx==arr.size() || target<0) return;

        if(target==0){
            ans.push_back(temp);
            return;
        }

        temp.push_back(arr[idx]);
        helper(idx+1,arr,target-arr[idx],ans,temp);
        helper(idx,arr,target-arr[idx],ans,temp);
        temp.pop_back();
        helper(idx+1,arr,target,ans,temp);

        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0,candidates,target,ans,temp);
        set<vector<int>> s;
        for(auto &it : ans){
            s.insert(it);
        }
        ans={};
        for(auto& it : s){
            ans.push_back(it);
        }
        return ans;
    }
};