class Solution {
public:
    int getX(int n){
        string num="";
        while(n!=0){
            int dig = n%10;
            if(dig!=0){
                num += to_string(dig);
            }
            n=n/10;
        }

        if(num=="") return 0;
        reverse(num.begin(),num.end());
        int ans=stoi(num);
        return ans;
    }
    long long getSum(int n){
        long long sum=0;
        while(n!=0){
            sum += n%10;
            n/=10;
        }
        return sum;
    }
    long long sumAndMultiply(int n) {
        int x=getX(n);
        long long sum = getSum(x);
        long long ans = 1ll*x*sum;

        return ans;
    }
};