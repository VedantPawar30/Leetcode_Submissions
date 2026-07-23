class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int bitLen =0;
        while(n){
            bitLen++;
            n=n >> 1;
        }

        if(nums.size()<=2){
            return nums.size();
        }
        int ans = pow(2,bitLen);
        cout<<ans<<endl;
        return ans;
        
    }
};