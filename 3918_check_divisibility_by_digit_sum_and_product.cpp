class Solution {
public:
    int helper(int n){
        int sum=0;
        int prod=1;
        while(n){
            int dig = n%10;
            sum += dig;
            prod *= dig;
            n/=10;
        }
        return sum + prod;
    }
    bool checkDivisibility(int n) {
        int d = helper(n);
        if(n%d==0) return true;
        return false;
    }
};