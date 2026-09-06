class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());

        int st=points[0][0];
        int en=points[0][1];
        int cnt=0;
        int n=points.size();
        for(int i=1;i<points.size();i++){
            int currSt = points[i][0];
            int currEn = points[i][1];

            if(currSt>=st && currSt<=en){
                cnt++;
                if(currEn<en){
                    en=currEn;
                    st=currSt;
                }
            }else{
                st=currSt;
                en=currEn;
            }
        }

        return n-cnt;
    }
};