class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        int n=nums.size();

        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }

        ans.push_back(pq.top().first);
        int i=1;
        int j = k;
        while(j<n){

            pq.push({nums[j],j});
            while(true){
                int top = pq.top().first;
                int idx = pq.top().second;
                if(idx>=i && idx<=j){
                    ans.push_back(top);
                    break;
                }

                pq.pop();
            }

            i++;
            j++;
        }

        return ans;

    }
};