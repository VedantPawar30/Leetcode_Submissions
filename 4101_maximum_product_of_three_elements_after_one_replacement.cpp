class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long max1=INT_MIN;
        long long max2=INT_MIN;
        long long max3=INT_MIN;
        long long min1 = INT_MAX;
        long long min2 = INT_MAX;

        for(int num:nums){
            if(num>=max1){
                max3=max2;
                max2=max1;
                max1=num;
            }

            else if(num>=max2){
                max3=max2;
                max2=num;
            }
            else if(num>=max3){
                max3 = num;
            }


            if(num<=min1){
                min2=min1;
                min1=num;
            }

            else if(num<=min2){
                min2 =num;
            }
        }

        int neg=0;
        long long p1=1;
        long long p2=1;
        
        //Three max case
        vector<long long> tmp = {max1,max2,max3};
        long long mini=INT_MAX;
        int minIdx=-1;
        for(int i=0;i<3;i++){
            if(tmp[i]<0) neg++;
            if(abs(tmp[i])<mini){
                mini = abs(tmp[i]);
                minIdx = i;
            }
        }

        if((neg%2==0 && tmp[minIdx]>=0) || (neg%2==1 && tmp[minIdx]<0)){
            tmp[minIdx] = 1e5;
        }
        else if((neg%2==0 && tmp[minIdx]<0) || (neg%2==1 && tmp[minIdx]>=0)){
            tmp[minIdx] = -1e5;
        }
        p1 = tmp[0]*tmp[1]*tmp[2];


        // 2 min and 1 max
        tmp = {min1,min2,max1};
        neg=0;
        mini=INT_MAX;
        minIdx=-1;
        for(int i=0;i<3;i++){
            if(tmp[i]<0) neg++;
            if(abs(tmp[i])<mini){
                mini = abs(tmp[i]);
                minIdx = i;
            }
        }

        if((neg%2==0 && tmp[minIdx]>=0) || (neg%2==1 && tmp[minIdx]<0)){
            tmp[minIdx] = 1e5;
        }
        else if((neg%2==0 && tmp[minIdx]<0) || (neg%2==1 && tmp[minIdx]>=0)){
            tmp[minIdx] = -1e5;
        }

        p2=tmp[0]*tmp[1]*tmp[2];


        return max(p1,p2);



    }
};