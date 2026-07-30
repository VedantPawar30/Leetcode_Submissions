class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high = nums.size()-1;
        if(nums.size()==1) return nums[0];
        while(low<=high){
            int mid = (low+high) >> 1;

            // If mid is my ans
            if(mid==0){
                if(mid != nums.size()-1 && nums[mid]!=nums[mid+1]) return nums[mid];
            }
            else if(mid==nums.size()-1){
                if(mid!=0 && nums[mid] != nums[mid-1]) return nums[mid];
            }else{
                if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            }



            if(mid%2==0){
                if(mid != nums.size()-1 && nums[mid] == nums[mid+1]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }else{
                if(mid!=0 && nums[mid]==nums[mid-1]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }



        }

        return -1;
    }
};