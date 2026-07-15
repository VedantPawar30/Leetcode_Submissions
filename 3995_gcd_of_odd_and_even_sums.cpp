class Solution {
public:
    int gcd(int a,int b){
        while(a>0 && b>0){
            if(a>b){
                a = a%b;
            }else{
                b=b%a;
            }
        }

        if(a==0) return b;
        return a;
    }
    int gcdOfOddEvenSums(int n) {
        int val1 =0;
        int val2=0;

        for(int i=1;i<=2*n;i++){
            if(i%2==0){
                val1+=i;
            }else{
                val2+=i;
            }
        }

        return gcd(val1,val2);


    }
};