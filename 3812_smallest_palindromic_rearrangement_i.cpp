class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);
        string ans="";
        for(char c:s){
            freq[c-'a']++;
        }
        int n=s.length();
        bool oddExist=false;
        char ch;
        for(int i=0;i<26;i++){
            int f =freq[i];
            if(f==0) continue;
            if(f%2==1){
                oddExist=true;
                ch = char(i+'a');
            }
            for(int k=0;k<f/2;k++){
                ans += char(i+'a');
            }
        }
        string tmp="";
        if(oddExist){
             tmp = ans;
            reverse(ans.begin(),ans.end());
            tmp += ch;
            tmp += ans;
        }else{
             tmp = ans;
            reverse(ans.begin(),ans.end());
            tmp += ans;
        }

        return tmp;

    }
};