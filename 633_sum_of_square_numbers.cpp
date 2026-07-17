class Solution {
public:
    bool judgeSquareSum(int c) {
        int val =sqrt(c);

        int st=0;
        int en=val;
        while(st<=en){
            long long sum = (1ll*st*st + 1ll*en*en);
            if(sum==c) return true;
            else if(sum>c){
                en--;
            }else{
                st++;
            }
        }

        return false;
    }
};