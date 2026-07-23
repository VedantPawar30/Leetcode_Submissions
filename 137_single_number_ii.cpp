class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans =0;
        for(int i=0;i<=31;i++){
            int cnt=0;
            int mask = 1<<i;
            for(int num : nums){
                if((num & (1<<i))) cnt++;
            }

            if(cnt%3!=0){
                ans = (ans | mask);
            }
        }

        return ans;
    }
};