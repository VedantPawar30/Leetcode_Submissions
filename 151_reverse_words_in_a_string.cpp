class Solution {
public:
    string reverseWords(string s) {
       string res="";
       int i=s.length()-1; 
       while(i>=0){
            int cnt=0;
            while(i>=0 && s[i]!=' '){
                cnt++;
                i--;
            }

            if(cnt!=0){
                string sub = s.substr(i+1,cnt);
                res += sub + " ";
            }

            i--;
       }
        res.pop_back();
       return res;
    }
};