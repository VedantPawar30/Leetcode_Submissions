class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<pair<int,int>> occur(26, {-1,-1});
        for(int i=0;i<s.length();i++){
            char c = s[i];
            int charIdx = c-'a';
            if(occur[charIdx].first==-1){
                occur[charIdx].first =i;
            }
            if(occur[charIdx].first != -1){
                occur[charIdx].second = i;
            }
            
        }
        vector<pair<int,int>> intervals;
        for(int i=0;i<26;i++){
            int l=occur[i].first;
            int r=occur[i].second;
            if(l==-1) continue;
            bool broke = false;
            for(int j=l;j<=r;j++){
                char ch = s[j];
                int idx = ch-'a';
                if(occur[idx].first<l){
                    //invalid
                    broke=true;
                    break;
                }

                r=max(r,occur[idx].second);
            }

            if(!broke){
                intervals.push_back({r,l});
            }

        }

        sort(intervals.begin(),intervals.end());

        int prevEnd=-1;
        vector<string> ans;
        for(auto &it:intervals){
            int st = it.second;
            int en = it.first;

            if(st>prevEnd){
                string str = s.substr(st,en-st+1);
                ans.push_back(str);
                prevEnd = en;
            }
        }

        return ans;



    }
};