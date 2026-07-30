class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        int cnt=0;
        for(int i=0;i<n;i++){
            int inc = i/8 + 1;
            cnt += inc;
        }

        return cnt;
    }
};