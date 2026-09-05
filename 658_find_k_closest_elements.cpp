class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int num : arr){
            int closeScore = abs(num-x);
            pq.push({closeScore,num});
        }
        vector<int> ans;
        while(k--){
            int num = pq.top().second;
            ans.push_back(num);
            pq.pop();
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};