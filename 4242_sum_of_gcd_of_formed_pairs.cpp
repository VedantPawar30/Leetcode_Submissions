class Solution {
public:
  
    int gcd(int a,int b){
        while(a>0 && b>0){
            if(a>b) a=a%b;
            else{
                b=b%a;
            }
        }
        if(a==0) return b;
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        vector<int> prefixGcd(n);
        int currMax = nums[0];
        prefixGcd[0] = gcd(currMax,nums[0]);

        for(int i=1;i<n;i++){
            currMax = max(currMax,nums[i]);
            prefixGcd[i] = gcd(currMax,nums[i]);
        }

        sort(prefixGcd.begin(),prefixGcd.end());
        int l=0;
        int r=n-1;
        while(l<r){
            ans += gcd(prefixGcd[l],prefixGcd[r]);
            l++;
            r--;
        }

        return ans;
    }
};