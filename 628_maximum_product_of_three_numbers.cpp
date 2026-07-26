class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int p1=1;
        int p2=1;

        for(int i=n-1;i>=n-3;i--){
            p1 *= nums[i];
        }

        p2 = nums[0]*nums[1]*nums[n-1];
        cout<<p1<<" "<<p2<<endl;

        return max(p1,p2);

    }
};