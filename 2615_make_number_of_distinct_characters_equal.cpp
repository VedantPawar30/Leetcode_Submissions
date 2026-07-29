class Solution {
public:
    int countDist(vector<int> &freq){
        int cnt=0;
        for(int i=0;i<freq.size();i++){
            if(freq[i]>0) cnt++;
        }
        return cnt;
    }
    bool isItPossible(string word1, string word2) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for(char c:word1){
            freq1[c-'a']++;
        }
        for(char c:word2){
            freq2[c-'a']++;
        }

        // int cnt1=countDist(freq1);
        // int cnt2=countDist(freq2);
        // if(cnt1==cnt2) return true;

        for(int i=0;i<26;i++){
            if(freq1[i]>=1){
                for(int j=0;j<26;j++){
                    if(freq2[j]>=1){
                        // if(i==j) continue;
                        freq1[i]--;
                        freq1[j]++;
                        freq2[i]++;
                        freq2[j]--;

                        int cnt1 = countDist(freq1);
                        int cnt2 = countDist(freq2);
                        if(cnt1==cnt2) return true;

                        freq1[i]++;
                        freq1[j]--;
                        freq2[i]--;
                        freq2[j]++;
                    }
                }
            }
        }

        return false;
    }
};