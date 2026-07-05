class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.length()>s.length()) return {};
        int len = p.length();
        vector<int> ans;
        int l=0;
        int r=0;
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(char c : p){
            freq1[c-'a']++;
        }

        while(r<len){
            freq2[s[r]-'a']++;
            r++;
        }

        if(freq1==freq2) ans.push_back(l);
        freq2[s[l]-'a']--;
        l++;
        while(r<s.length()){
            freq2[s[r]-'a']++;
            if(freq1==freq2){
                ans.push_back(l);
            }

            r++;
            freq2[s[l]-'a']--;
            l++;
            
        }

        return ans;
    }
};