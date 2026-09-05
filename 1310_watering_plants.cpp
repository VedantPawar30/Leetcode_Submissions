class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int currCap = capacity;

        int steps=0;

        for(int i=0;i<plants.size()-1;i++){
            int amt=plants[i];
            int nxtAmt = plants[i+1];
            currCap -= amt;
            steps++;
            if(nxtAmt>currCap){
                int back = i+1;
                int ret = back;

                steps += back+ret;
                currCap = capacity;

            }


        }

        return steps+1;
    }
};