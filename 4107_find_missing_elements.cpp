class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int,bool> mp;
        int maxi=0;
        int mini=101;
        for(int num : nums){
            mp[num]=true;
            maxi=max(maxi,num);
            mini=min(mini,num);
        }
        
        vector<int> ans;
        for(int i=mini;i<=maxi;i++){
            if(!mp[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};