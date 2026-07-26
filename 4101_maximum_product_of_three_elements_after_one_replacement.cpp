class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        for(int &x:nums){
            x=abs(x);
        }

        int max1=INT_MIN;
        int max2=INT_MIN;
        for(int x:nums){
            if(x>=max1){
                max2=max1;
                max1=x;
            }

            else if(x>=max2){
                max2=x;
            }
        }

        return 1ll*max1*max2*1e5;
    }
};