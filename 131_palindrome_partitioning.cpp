class Solution {
public:
    bool isPal(string &s){
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void helper(string &s, vector<vector<string>> &ans, vector<string> &temp){
        if(s.length()==0){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<s.length();i++){
            string part = s.substr(0,i+1);
            if(isPal(part)){
                temp.push_back(part);
                string next = s.substr(i+1);
                helper(next,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        helper(s,ans,temp);
        return ans;
    }
};