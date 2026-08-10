class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> squares;
        int i=1;
        while(i*i<=n){
            squares.push_back(i*i);
            i++;
        }
        
        vector<int> dp(n+1,false);

        for(int i=1;i<=n;i++){

            for(int sq : squares){
                if(sq>i) break;
                if(!dp[i-sq]){
                    dp[i] =true;
                    break;
                }
            }
        }

        return dp[n];

    }
};