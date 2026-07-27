class Solution {
public:
    bool isPalindrome(string &s, int i,int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    string longestPalindrome(string s) {
        int maxi=0;
        int start=0;

        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(isPalindrome(s,i,j)){
                    if(j-i+1>maxi){
                        maxi = j-i+1;
                        start=i;
                    }
                }
            }
        }

        return s.substr(start,maxi);
    }
};