class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int n=nums.size();
        while(low<=high){
            int mid = (low+high) >> 1;

            if(nums[mid]==target) return mid;

            else if(nums[mid] < nums[0]){
                if(target < nums[mid]){
                    high=mid-1;
                }
                else if(target>nums[mid] && target<=nums[n-1]){
                    low=mid+1;
                }
                else if(target>nums[mid] && target>nums[n-1]){
                    high =mid-1;
                }
            }

            else if(nums[mid] >= nums[0]){
                if(target>nums[mid]){
                    low =mid+1;
                }
                else if(target<nums[mid] && target>=nums[0]){
                    high=mid-1;
                }else if(target<nums[mid] && target<nums[0]){
                    low = mid+1;
                }
            }
        }

        return -1;
    }
};