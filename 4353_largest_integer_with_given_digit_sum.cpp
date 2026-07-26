class Solution {
public:
    int largestInteger(int n, int s) {
        string ans="";
        while(n){
            if(s>=9){
                ans += '9';
                s-=9;
            }else{
                char c = s+'0';
                ans += c;
                s-=s;
            }
            n--;
        }

        if(s!=0){
            return -1;
        }
        if(ans=="") return 0;
        int res = stoi(ans);
        return res;
    }
};