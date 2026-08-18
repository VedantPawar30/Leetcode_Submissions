class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }
        int maxi=-1;
        if(k==1){
            for(int num : nums){
                if(mp[num]==1){
                    maxi = max(maxi,num);
                }
            }
            return maxi;
        }

        if(k==nums.size()){
            for(int num : nums){
                maxi = max(maxi,num);
            }
            return maxi;
        }

        if(mp[nums[0]]==1 && mp[nums[nums.size()-1]]==1){
            return max(nums[0],nums[nums.size()-1]);
        }
        else if(mp[nums[0]]>1 && mp[nums[nums.size()-1]]==1){
            return nums[nums.size()-1];
        }
        else if(mp[nums[0]]==1 && mp[nums[nums.size()-1]]>1){
            return nums[0];
        }

        return -1;


    }
};