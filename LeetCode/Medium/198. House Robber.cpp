// Link: https://leetcode.com/problems/house-robber/
// TimeComplexity: O(n), where n is the length of the input array nums
// SpaceComplexity: O(1), since the dp array has a fixed size of 101
class Solution {
public: 
    int dp[101];
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        memset(dp, -1, sizeof dp);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        return dp[n-1];
    }
};
//==========================================================================================================================================
// TimeComplexity: O(n), 
// SpaceComplexity: O(1), using only two variables
class Solution {
public: 
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int current = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};
