class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,bool> mp2;
        for(int num : arr2){
            mp2[num]=true;
        }

        unordered_map<int,int> mp1;
        vector<int> remaining;
        for(int num : arr1){
            if(mp2[num]){
                mp1[num]++;
            }else{
                remaining.push_back(num);
            }
        }

        sort(remaining.begin(),remaining.end());
        vector<int> ans;
        for(int num : arr2){
            while(mp1[num]>0){
                ans.push_back(num);
                mp1[num]--;
            }
        }

        ans.insert(ans.end(), remaining.begin(), remaining.end());
        return ans;

    }
};