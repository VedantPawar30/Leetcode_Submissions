class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26,0);
        int l=0;
        int r=0;
        int maxi=1;
        while(r<s.length()){
            freq[s[r]-'a']++;

            while(l<r &&freq[s[r]-'a']>2){
                freq[s[l]-'a']--;
                l++;
            }

            maxi = max(maxi,r-l+1);
            r++;
        }

        return maxi;

    }
};