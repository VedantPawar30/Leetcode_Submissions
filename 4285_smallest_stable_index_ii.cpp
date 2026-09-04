class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixMax(n, 0);
        vector<int> suffixMin(n, 0);
        prefixMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }

        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }

        int miniIdx = n;
        for (int i = 0; i < n; i++) {
            int maxi = prefixMax[i];
            int mini = suffixMin[i];
            if (maxi - mini <= k) {
                miniIdx = min(miniIdx, i);
            }
        }

        if (miniIdx == n)
            return -1;
        return miniIdx;
    }
};