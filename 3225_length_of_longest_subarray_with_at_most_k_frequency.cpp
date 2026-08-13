class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int maxi=1;
        int l=0;
        int r=0;

        while(r<nums.size()){
            mp[nums[r]]++;

            while(l<r && mp[nums[r]]>k){
                mp[nums[l]]--;
                l++;
            }

            maxi = max(maxi,r-l+1);
            r++;
        }

        return maxi;
    }
};