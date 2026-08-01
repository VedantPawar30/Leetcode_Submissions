class Solution {
public:
    bool helper(long long sc1, long long sc2, deque<long long> &n, int turn){
        if(n.empty()){
           return sc1>=sc2;
        }

      // Player 1 turn
        if(!turn){
            long long num = n.front();
            n.pop_front();
            bool first = helper(sc1+num,sc2,n,1);
            n.push_front(num);

            num = n.back();
            n.pop_back();
            bool last = helper(sc1+num,sc2,n,1);
            n.push_back(num);

            return first || last;

        }

        //Player 2 turn
        else{
            long long num = n.front();
            n.pop_front();
            bool first = helper(sc1,sc2+num,n,0);
            n.push_front(num);

            num = n.back();
            n.pop_back();
            bool last = helper(sc1,sc2+num,n,0);
            n.push_back(num);

            return first && last;
        } 
       
    }
    bool predictTheWinner(vector<int>& nums) {
        long long score1=0;
        long long score2=0;
        bool win =false;
        deque<long long> n(nums.begin(),nums.end());
        int turn=0;
        return helper(score1,score2,n,turn);

        
    }
};