//https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/
//TimeComplexity : O(n)
//SpaceComplexity: O(1)
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int maxLen = 1;
        int curLenInc = 1;
        int curLenDec = 1;
        
        for (int i = 0; i < n-1; i++) 
        {
            if (nums[i] < nums[i + 1]) {
                curLenInc++;
                curLenDec = 1;
            } 
            else if (nums[i] > nums[i + 1]) {
                curLenDec++;
                curLenInc = 1;
            } 
            else 
            {
                curLenInc = 1;
                curLenDec = 1;
            }
            maxLen = max(maxLen, max(curLenInc, curLenDec));
        }
        return maxLen;
    }
};
