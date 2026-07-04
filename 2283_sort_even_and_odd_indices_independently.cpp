class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> even;
        vector<int> odd;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                even.push_back(nums[i]);
            }else{
                odd.push_back(nums[i]);
            }
        }

        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end(),greater<int>());

        int i=0;
        int j=0;
        int k=0;
        while(i<nums.size()){
            if(i%2==0){
                nums[i] = even[j];
                j++;
            }else{
                nums[i] = odd[k];
                k++;
            }

            i++;
        }

        return nums;
    }
};