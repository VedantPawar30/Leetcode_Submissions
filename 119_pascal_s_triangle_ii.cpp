class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans(rowIndex+1);
        ans[0] = {1};
        if(rowIndex == 0){
            return {1};
        }

        ans[1] = {1,1};

        for(int i=2;i<=rowIndex;i++){
            vector<int> prev = ans[i-1];
            vector<int> tmp;
            tmp.push_back(1);
            for(int j=1;j<prev.size();j++){
                tmp.push_back(prev[j-1]+prev[j]);
            }
            tmp.push_back(1);
            ans[i] =tmp;
        }

        return ans[rowIndex];
    }
};