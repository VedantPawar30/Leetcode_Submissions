class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int cnt1 =0;
        for(char c : s){
            if(c=='1'){
                cnt1++;
            }
        }
        
        string aug = '1' + s + '1';
        vector<string> splits;
        string subtmp = "";
        subtmp += aug[0];
        for(int i=1;i<aug.length();i++){
            if(aug[i]==aug[i-1]){
                subtmp += aug[i];
            }else{
                splits.push_back(subtmp);
                subtmp="";
                subtmp += aug[i];
            }
        }
        
        splits.push_back(subtmp);
        
        int maxi=0;
        int n=splits.size();
        for(int i=1;i<n-1;i++){
            string temp =splits[i];
            if(temp[0] =='1'){
                int cnt = splits[i-1].length() + splits[i+1].length();
                maxi = max(maxi,cnt);
            }
        }
        
        
        return maxi + cnt1;
    }
};