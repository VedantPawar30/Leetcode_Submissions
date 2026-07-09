class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        unordered_map<int,int> mp;
        int idx=0;
        vector<vector<int>> conn;
        vector<int> temp;
        temp.push_back(0);
        mp[0] =idx;
        for(int i=1;i<n;i++){
           if(abs(nums[i] - nums[i-1])<=maxDiff){
                temp.push_back(i);
                mp[i] = idx;
           }else{
                conn.push_back(temp);
                temp = {};
                temp.push_back(i);
                idx++;
                mp[i] =idx;
           }

        }
        vector<bool> ans;
        for(int i=0;i<queries.size();i++){
            int node1=queries[i][0];
            int node2 = queries[i][1];

            if(mp[node1]==mp[node2]){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }

        return ans;
    }
};