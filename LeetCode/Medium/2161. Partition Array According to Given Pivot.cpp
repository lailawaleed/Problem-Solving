// Link: https://leetcode.com/problems/partition-array-according-to-given-pivot/description/
// TimeComplexity  :O(N)
// SpaceComplexity : O(N) 
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result(nums.size());
        int left = 0, right = nums.size() - 1;

        // First populate less and greater than pivot
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < pivot) {
                result[left++] = nums[i];
            }
            if (nums[nums.size() - 1 - i] > pivot) {
                result[right--] = nums[nums.size() - 1 - i];
            }
        }

        // Second pass to populate equal to pivot
        for (int i = left; i <= right; ++i) {
            result[i] = pivot;
        }

        return result;
    }
};
