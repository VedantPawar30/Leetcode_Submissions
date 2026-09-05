class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mini1 = INT_MAX;
        int mini2 = INT_MAX;

        for (int price : prices) {
            if (price < mini1) {
                mini2 = mini1;
                mini1 = price;
            }

            else if (price < mini2) {
                mini2 = price;
            }
        }

        if (mini1 + mini2 > money)
            return money;

        return money - (mini1 + mini2);
    }
};