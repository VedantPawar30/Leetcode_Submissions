class Solution {
public:
    long long calculateScore(string s) {
        int n=s.length();
        vector<bool> marked(n,false);
        unordered_map<int,vector<int>> mp;
        mp[s[0]-'a'].push_back(0);
        long long score=0;
        for(int i=1;i<n;i++){
            char ch = s[i];
            int chIdx = ch-'a';
            int mirrIdx = 25-chIdx;

            if(!mp[mirrIdx].empty() && !marked[mp[mirrIdx].back()]){
                score += i-mp[mirrIdx].back();
                marked[mp[mirrIdx].back()]=true;
                marked[i] =true;
                mp[mirrIdx].pop_back();
            }else{
                mp[chIdx].push_back(i);
            }

        }

        return score;
    }
};