class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int mult=1;
        unordered_map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }

        while(true){
            int missNum = k*mult;
            if(!mp[missNum]) return missNum;
            mult++;
        }

        return -1;
    }
};