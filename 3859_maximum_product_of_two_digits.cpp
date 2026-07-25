class Solution {
public:
    int maxProduct(int n) {
        int a=0;
        int b=0;
        int t=n;
        vector<int> digs;
        while(t!=0){
            int dig = t%10;
            digs.push_back(dig);
            t/=10;
        }

        a=digs[0];
        for(int i=1;i<digs.size();i++){
            // if greater than First max
            if(digs[i]>a){
                b=a;
                a=digs[i];
            }

            else if(digs[i]<=a && digs[i]>b){
                b=digs[i];
            }
        }

        return a*b;
    }
};