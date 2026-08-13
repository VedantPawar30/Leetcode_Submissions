class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.length()<k) return 0;

        vector<int> freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        int idx=-1;
        for(int i=0;i<s.length();i++){
            if(freq[s[i]-'a']<k){
                idx=i;
                break;
            }
        }

        if(idx==-1) return s.length();

        string sub1 = s.substr(0,idx);
        string sub2 = s.substr(idx+1);

        int leftMax = longestSubstring(sub1,k);
        int rightMax=longestSubstring(sub2,k);

        return max(leftMax,rightMax);

    }
};