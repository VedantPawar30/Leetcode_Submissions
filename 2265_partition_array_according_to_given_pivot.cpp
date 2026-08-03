class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int cnt1=0;
        int cnt2=0;
        int cnt3=0;
        for(int num : nums){
            if(num<pivot) cnt1++;
            if(num==pivot) cnt2++;
            if(num>pivot) cnt3++;
        }

        int i=0;
        int j=cnt1;
        int k=j+cnt2;
        int idx=0;
        vector<int> tmp(nums.size());
        while(idx<nums.size()){
            if(nums[idx]<pivot){
                tmp[i]=nums[idx];
                i++;
            }

            if(nums[idx]==pivot){
                tmp[j]=nums[idx];
                j++;
            }

            if(nums[idx]>pivot){
                tmp[k] =nums[idx];
                k++;
            }
            idx++;
        }

        return tmp;
    }
};