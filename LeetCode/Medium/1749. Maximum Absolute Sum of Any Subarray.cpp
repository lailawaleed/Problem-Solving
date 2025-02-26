//Link  :https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
//TimeComplexity  : O(N)
//SpaceComplexity : O(1)
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0;
        int minSum = 0;
        int currentSum = 0;
        int maxAbsSumReached = 0;

        for (int num : nums) {
            currentSum += num;
            minSum = min(minSum, currentSum);
            maxSum = max(maxSum, currentSum);
            maxAbsSumReached = max(maxAbsSumReached, abs(currentSum - (currentSum > 0 ? minSum : maxSum)));
        }

        return maxAbsSumReached;
    }
};
//-------------------------------------------------- 2) Second Solution (based on Observation)-------------------------------------------------------------------
//TimeComplexity  : O(N)
//SpaceComplexity : O(1)
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0;
        int minSum = 0;
        int currentSum=0;

        for (int num : nums) {
            currentSum += num;
            minSum = min(minSum, currentSum);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum-minSum;
    }
};
