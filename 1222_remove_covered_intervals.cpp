class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a,const vector<int> &b){
            return a[0]<b[0];
        });
        int cnt=1;
        // vector<pair<int,int>> res;
        // res.push_back({intervals[0][0],intervals[0][1]});
        int l2=intervals[0][0];
        int r2=intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            int l1=intervals[i][0];
            int r1=intervals[i][1];
            // int l2 = res.back().first;
            // int r2 =res.back().second;

            if(r2>=r1){
                continue;
            }
            else if(l1==l2 && r2<r1){
                // res.pop_back();
                // res.push_back({l1,r1});
                l2=l1;
                r2=r1;
            }

            else if(l1>l2 && r2<r1){
                cnt++;
                l2=l1;
                r2=r1;
            }
        }

        return cnt;
    }
};