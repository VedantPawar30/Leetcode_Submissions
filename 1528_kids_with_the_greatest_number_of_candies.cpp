class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maxi=-1;
        for(int num:candies){
            maxi=max(maxi,num);
        }
        for(int num : candies){
            if(num + extraCandies>=maxi) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};