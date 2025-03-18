//Link: https://leetcode.com/problems/longest-nice-subarray/
//TimeComplexity  :O(n * logn *32) 
//SpaceComplexity :O(1)
class Solution {
public:
    int bits[32] = {0}; 

    void update(int num, int operation) {
        for (int j = 0; j < 32; j++) {
            if (num & (1 << j)) {
                bits[j] += operation; 
            }
        }
    }
    bool isNice(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Reset the bits array before processing
        memset(bits, 0, sizeof(bits));

        for (int i = 0; i < target; i++) {
            update(nums[i], 1); // Add the contribution of nums[i]
        }

        // Check if the first window is nice
        bool isNiceWindow = true;
        for (int j = 0; j < 32; j++) {
            if (bits[j] > 1) {
                isNiceWindow = false;
                break;
            }
        }
        if (isNiceWindow) return true;

        for (int left = 1; left <= n - target; left++) {
            int right = left + target - 1; // Right boundary of the new window

            // Remove the contribution of nums[left - 1] (sliding out of the window)
            update(nums[left - 1], -1);

            // Add the contribution of nums[right] (sliding into the window)
            update(nums[right], 1);

            // Check if the current window is nice
            isNiceWindow = true;
            for (int j = 0; j < 32; j++) {
                if (bits[j] > 1) {
                    isNiceWindow = false;
                    break;
                }
            }
            if (isNiceWindow) return true;
        }

        return false;
    }

    int longestNiceSubarray(vector<int>& nums) {
        int left = 1;
        int right = nums.size();
        int answer = 1;

        // Binary search to find the maximum possible 'target'
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isNice(nums, mid)) {
                left = mid + 1;
                answer = mid;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }
};
//===================================================== 2) Second Solution ================================================================

//TimeComplexity  :O(n)
//SpaceComplexity :O(1)
#include <vector>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int currOr = 0;  // Cumulative OR of the current window
        int maxLen = 0;  // Longest nice subarray length
        int left = 0;    // Left pointer of the sliding window
        
        for (int right = 0; right < n; ++right) {
            // Check if adding nums[right] introduces overlapping bits
            while ((currOr & nums[right])) {
                // Shrink the window by removing nums[left] from currOr
                currOr ^= nums[left];
                left++;
            }
            // Add nums[right] to the window
            currOr |= nums[right];
            // Update max length
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};
