class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<vector<int>> adj(n);

        // email -> first account that contains this email
        unordered_map<string, int> mp;

        // Build graph
        for(int i = 0; i < n; i++) {

            for(int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                if(mp.find(email) == mp.end()) {
                    // First time seeing this email
                    mp[email] = i;
                }
                else {
                    // Same email exists in another account
                    int prevAccount = mp[email];

                    adj[i].push_back(prevAccount);
                    adj[prevAccount].push_back(i);
                }
            }
        }

        vector<vector<string>> ans;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){   
            if(!visited[i]){
                vector<string> mails;
                mails.push_back(accounts[i][0]);
                stack<int> st;
                st.push(i);
                visited[i]=true;
                set<string> s;
                while(!st.empty()){
                    int node = st.top();
                    st.pop();

                    for(int j=1;j<accounts[node].size();j++){
                        s.insert(accounts[node][j]);
                    }

                    for(auto &neigh : adj[node]){
                        if(!visited[neigh]){
                            st.push(neigh);
                            visited[neigh]=true;
                        }
                    }
                }

                for(auto &it : s){
                    mails.push_back(it);
                }
                ans.push_back(mails);
            }
        }

        return ans;
        



    }
};