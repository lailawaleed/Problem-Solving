// Link: https://leetcode.com/problems/house-robber-iv/
// TimeComplexity: O(n log M) ==> where n is nums.length,
//                                M is the range of nums values (max - min + 1)
// SpaceComplexity: O(1)
class Solution {
public:
    bool canRob(vector<int> &nums, int k, int target) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= target) {
                count++;
                i++;
            }
            if (count >= k) {
                return true;
            }
        }
        return count >= k;
    }

    int minCapability(vector<int> &nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canRob(nums, k, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
