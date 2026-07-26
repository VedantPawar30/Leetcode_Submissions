class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int n = series1.size() + series2.size();
        vector<vector<int>> ans;
        int i=0,j=0;
        int idx=0;
        while(i<series1.size() && j<series2.size()){
            int val1,val2;
            if(series1[i][0] < series2[j][0]){
                val1 = series1[i][0];
                val2 = series1[i][1] + series2[j][1];
                i++;
            }else if(series1[i][0] > series2[j][0]){
                val1 =series2[j][0];
                val2 = series1[i][1] + series2[j][1];
                j++;
            }else{
                val1 = series1[i][0];
                val2 = series1[i][1] + series2[j][1];
                i++;
                j++;
            }
            vector<int> temp = {val1,val2};
            ans.push_back(temp);
            idx++;
        }

        while(i<series1.size()){
            int val1=series1[i][0];
            int val2 = series1[i][1];
            vector<int> temp = {val1,val2};
            ans.push_back(temp);
            idx++;
            i++;
        }

        while(j<series2.size()){
            int val1=series2[j][0];
            int val2 = series2[j][1];
            vector<int> temp = {val1,val2};
            ans.push_back(temp);
            idx++;
            j++;
        }

        return ans;
    }
};