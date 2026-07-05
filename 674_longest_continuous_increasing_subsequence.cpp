class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int currLen=1;
        int maxLen = 1;

        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                currLen++;
            }else{
                maxLen = max(maxLen,currLen);
                currLen=1;
                
            }
        }

        maxLen = max(currLen,maxLen);

        return maxLen;
    }
};