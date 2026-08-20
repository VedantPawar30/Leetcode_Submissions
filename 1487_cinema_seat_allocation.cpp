class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,set<int>> mp;
        int cnt=0;
        for(auto &it : reservedSeats){
            mp[it[0]].insert(it[1]);
        }

        for(auto &it : mp){
            set<int> temp = it.second;
            bool first = true;
            for(int i=2;i<=5;i++){
                if(temp.find(i)!=temp.end()){
                    first=false;
                    break;
                }
            }

            bool second=true;
            for(int i=4;i<=7;i++){
                if(temp.find(i)!=temp.end() || first){
                    second=false;
                    break;
                }
            }
            bool third=true;
            for(int i=6;i<=9;i++){
                if(temp.find(i)!=temp.end() || second){
                    third=false;
                    break;
                }
            }

            if(first) cnt++;
            if(second) cnt++;
            if(third) cnt++;
        }

        int m=mp.size();
        int remain = (n-m)*2;
        cnt += remain;
        return cnt;
    }
};