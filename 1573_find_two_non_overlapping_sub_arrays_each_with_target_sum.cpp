class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int l=0;
        int r=0;
        int sum=0;
        int ans=INT_MAX;
        vector<int> minLen(arr.size(),INT_MAX);
        while(r<arr.size()){
            sum += arr[r];

            while(sum>target){
                sum -= arr[l];
                l++;
            }

            if(r>0){
                minLen[r] = minLen[r-1];
            }

            if(sum==target){
                int len = r-l+1;

                if(l>0 && minLen[l-1]!=INT_MAX){
                    ans = min(ans,len + minLen[l-1]);
                }


               minLen[r] = min(minLen[r],len);
            }

            r++;
        }

        if(ans==INT_MAX) return -1;
        return ans;
    }
};