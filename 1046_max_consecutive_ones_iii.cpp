class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int> freq(2,0);
        int l=0;
        int r=0;
        int maxi=0;
        while(r<nums.size()){
            freq[nums[r]]++;

            while(l<=r && freq[0]>k){
                freq[nums[l]]--;
                l++;
            }

            maxi = max(maxi,r-l+1);
            r++;
        }

        return maxi;
    }
};