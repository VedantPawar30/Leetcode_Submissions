class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int tmp=n;
            int prod=1;
            while(tmp){
                prod *= tmp%10;
                tmp/=10;
            }
            if(prod%t==0) return n;
            n++;
        }

        return -1;
    }
};