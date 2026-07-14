class Solution {
public:
    string removeTrailingZeros(string num) {
        int r=num.length()-1;
        while(r>=0){
            if(num[r]!='0') break;
            r--;
        }
        string ans =num.substr(0,r+1);
        return ans;
    }
};