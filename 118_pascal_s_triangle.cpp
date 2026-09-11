class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0] = {1};
        if(numRows == 1){
            return ans;
        }

        ans[1] = {1,1};

        for(int i=2;i<numRows;i++){
            vector<int> prev = ans[i-1];
            vector<int> tmp;
            tmp.push_back(1);
            for(int j=1;j<prev.size();j++){
                tmp.push_back(prev[j-1]+prev[j]);
            }
            tmp.push_back(1);
            ans[i] =tmp;
        }

        return ans;
        
    }
};