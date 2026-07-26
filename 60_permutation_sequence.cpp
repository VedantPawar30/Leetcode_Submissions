class Solution {
public:
    void getAll(vector<char> &nums,string temp,vector<bool> &visited, vector<string> &all, int n){
        //base case
        if(temp.size()==n){
            all.push_back(temp);
            return;
        }

        for(char c : nums){
            if(!visited[c-'0']){
                temp += c;
                visited[c-'0']=true;
                getAll(nums,temp,visited,all,n);
                visited[c-'0']=false;
                temp.pop_back();
            }
        }
    }
    string getPermutation(int n, int k) {
        vector<char> nums;
        char tot = n + '0';
        for(char i='1';i<=tot;i++){
            nums.push_back(i);
        }

        vector<bool> visited(n+1,false);
        vector<string> all;
        string temp="";
        getAll(nums,temp,visited,all,n);

        return all[k-1];
    }
};