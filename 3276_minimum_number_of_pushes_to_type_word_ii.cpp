class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(char c:word){
            freq[c-'a']++;
        }
        int uniChars=0;
        for(int i=0;i<26;i++){
            if(freq[i]>0) uniChars++;
        }
        int cnt=0;
        int charsDone=0;
        while(true){
            int maxFreq=0;
            int idx=-1;
            for(int i=0;i<26;i++){
                if(freq[i]>maxFreq){
                    maxFreq=freq[i];
                    idx=i;
                }
            }
            
            int onePush = charsDone/8 +1;
            cnt += freq[idx]*onePush;
            cout<<cnt<<endl;
            freq[idx]=0;
            charsDone++;

            if(charsDone==uniChars) break;


        }

        return cnt;


    }
};