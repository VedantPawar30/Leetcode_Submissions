class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = "123456789";
        vector<int> nums;

        for(int i=0;i<8;i++){
            for(int j=i+1;j<9;j++){
                string curr = str.substr(i,j-i+1);
                int curr1 = stoi(curr);
                if(curr1>=low && curr1<=high) nums.push_back(curr1);
            }
        }

        sort(nums.begin(),nums.end());
        return nums;
    }
};