//Link : https://leetcode.com/problems/count-number-of-bad-pairs/description/
//Time Complexity :  O(N)
//Space Complexity : O(N)
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int arraySize = nums.size();
        unordered_map<int, int> differenceCountMap;

        // Count the occurrences of (num - index)
        for (int index = 0; index < arraySize; index++) {
            differenceCountMap[nums[index] - index]++;
        }

        long long goodPairsCount = 0;
        for (auto pair : differenceCountMap) {
            if (pair.second > 1) {
                long long count = static_cast<long long>(pair.second);
                goodPairsCount += count * (count - 1) / 2;
            }
        }

        long long totalPairsCount = static_cast<long long>(arraySize) * (arraySize - 1) / 2;
        return totalPairsCount - goodPairsCount;
    }
};
