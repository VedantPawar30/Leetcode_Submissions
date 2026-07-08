class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int maxSum=0;
        int n=nums.size();
        vector<int> suffixMax(n);
        suffixMax[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffixMax[i] = max(nums[i],suffixMax[i+1]);
        }

        for(int i=0;i<n-k;i++){
            maxSum = max(maxSum,nums[i] + suffixMax[i+k]);
        }
        
        return maxSum;
    }
};