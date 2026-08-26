class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l=0;
        int r=0;
        int minLen = INT_MAX;
        string mini="";
        vector<int> freq(2,0);

        while(r<s.length()){
            freq[s[r]-'0']++;

            while(l<=r && freq[1]==k){
                int len=r-l+1;
                if(len < minLen){
                    
                    string t = s.substr(l,len);
                    mini = t;
                    minLen=len;
                }
                if(len==minLen){
                    string t = s.substr(l,len);
                    if(t<mini){
                        mini=t;
                        minLen=len;
                    }
                }
                freq[s[l]-'0']--;
                l++;
            }

            

            r++;
        }

        return mini;
    }
};