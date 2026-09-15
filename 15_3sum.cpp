class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> res;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int numi = nums[i];
            int target = -numi;
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
               
                if(nums[j]+nums[k] == target){
                    if(i!=j && i!=k){
                        vector<int> temp = {numi,nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        res.insert(temp);
                    }
                    
                    j++;
                    k--;
                }

                else if(nums[j]+nums[k]>target) k--;
                else j++;
                
            }
        }

        for(auto &it : res){
            ans.push_back(it);
        }

        return ans;
    }
};