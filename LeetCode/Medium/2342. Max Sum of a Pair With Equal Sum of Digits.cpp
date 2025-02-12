//Link : https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/
//Time Complexity : O(N∗Log(N))
//Space Complexity : O(N)
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, multiset<int>> digitSumToNumbersMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int currentNumber = nums[i];
            int digitSum = 0;
            while (currentNumber >= 1) {
                digitSum += currentNumber % 10;
                currentNumber /= 10;
            }
            digitSumToNumbersMap[digitSum].insert(nums[i]);
        }
        
        int maximumSum = -1;
        for (auto it : digitSumToNumbersMap) {
            auto numSet = it.second;
            if (numSet.size() > 1) {
                int sumOfTwoLargest = *(numSet.rbegin()) + *(next(numSet.rbegin()));
                maximumSum = max(maximumSum, sumOfTwoLargest);
            }
        }
        return maximumSum;
    }
};
//------------------------------------------------------- 2) Second Solution --------------------------------------------------------------------------
//Time Complexity : O(N∗Log(N))
//Space Complexity : O(N)
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<pair<int, int>> digitSumPairs;
        digitSumPairs.reserve(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            int currentNumber = nums[i];
            int digitSum = 0;
            while (currentNumber) {
                digitSum += currentNumber % 10;
                currentNumber /= 10;
            }
            digitSumPairs.push_back({digitSum, nums[i]});
        }
        
        sort(digitSumPairs.begin(), digitSumPairs.end());
        
        int maximumSum = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (digitSumPairs[i].first == digitSumPairs[i - 1].first) {
                maximumSum = max(maximumSum, digitSumPairs[i].second + digitSumPairs[i - 1].second);
            }
        }        
        return maximumSum;
    }
};
//------------------------------------------------------- 3) Third Solution --------------------------------------------------------------------------
//Time Complexity : O(N∗Log(N))
//Space Complexity : O(N)
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSumToNumbersMap;

        int maximumSum=-1;
        for (int i = 0; i < nums.size(); i++) {
            int currentNumber = nums[i];
            int digitSum = 0;
            while (currentNumber >= 1) {
                digitSum += currentNumber % 10;
                currentNumber /= 10;
            }
            if(digitSumToNumbersMap[digitSum]) {
                maximumSum = max(maximumSum, nums[i] + digitSumToNumbersMap[digitSum]);
                if(nums[i]>digitSumToNumbersMap[digitSum]){
                    digitSumToNumbersMap[digitSum]=nums[i];
                }
            }
            else{
                digitSumToNumbersMap[digitSum]=nums[i];
            }

        }
        return maximumSum;
    }
};
//---------------------------------------------------- 3) Third Solution (Optimized)--------------------------------------------------------------------------
//Time Complexity : O(N)
//Space Complexity : O(1)
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int digitSumToNumbersMap[82]={0};

        int maximumSum=-1;
        for (int i = 0; i < nums.size(); i++) {
            int currentNumber = nums[i];
            int digitSum = 0;
            while (currentNumber >= 1) {
                digitSum += currentNumber % 10;
                currentNumber /= 10;
            }
            if(digitSumToNumbersMap[digitSum]) {
                maximumSum = max(maximumSum, nums[i] + digitSumToNumbersMap[digitSum]);
                if(nums[i]>digitSumToNumbersMap[digitSum]){
                    digitSumToNumbersMap[digitSum]=nums[i];
                }
            }
            else{
                digitSumToNumbersMap[digitSum]=nums[i];
            }

        }
        return maximumSum;
    }
};
