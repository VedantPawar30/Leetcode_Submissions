class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int maxVowels(string s, int k) {
        int maxi=0;
        int l=0;
        int r=0;
        int cnt=0;
        while(r<k){
            if(isVowel(s[r])) cnt++;
            r++;
        }

        maxi = max(maxi,cnt);

        if(isVowel(s[l])){
            cnt--;
        }

        l++;

        while(r<s.length()){
            if(isVowel(s[r])) cnt++;

            maxi = max(maxi,cnt);

            r++;
            if(isVowel(s[l])) cnt--;
            l++;
        }


        return maxi;


    }
};