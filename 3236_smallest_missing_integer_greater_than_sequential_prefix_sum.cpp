class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();

        int maxSum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                maxSum += nums[i];
            }else{
                break;
            }

        }


        unordered_map<int,bool> mp;
        for(int num : nums){
            mp[num]=true;
        }

        while(true){
            if(!mp[maxSum]) return maxSum;

            maxSum++;
        }

        return -1;
    }
};