class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            int idx = 26 - (s[i] -'a');
            int prod = idx*(i+1);
            ans += prod;
        }

        return ans;
    }
};