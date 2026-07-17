class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l=0;
        long long r=num;


        while(l<=r){
            long long mid = l+(r-l)/2;

            long long sq = mid*mid;

            if(sq==num) return true;
            else if(sq>num){
                r=mid-1;
            }else{
                l=mid+1;
            }

        }

        return false;
    }
};