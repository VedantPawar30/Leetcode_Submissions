class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi = INT_MIN;
        int miniIdx=-1;
        int maxiIdx=-1;
        int n=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mini){
                mini=nums[i];
                miniIdx=i;
            }

            if(nums[i]>maxi){
                maxi = nums[i];
                maxiIdx=i;
            }
        }

        //Front side
        int del1 = max(miniIdx,maxiIdx) + 1;

        //BackSide
        int del2= n- min(miniIdx,maxiIdx) + 1;
        

        //Min Front Side and Max BackSide
        int del3 = miniIdx+1 + (n-maxiIdx)+1;


        //Mini back and maxi frontside
        int del4 = maxiIdx+1 + (n-miniIdx)+1;
        

        return min({del1,del2,del3,del4});


    }
};