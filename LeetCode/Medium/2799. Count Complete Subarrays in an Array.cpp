// TimeComplexity: O(n²)
// SpaceComplexity: O(k) K:number of distinct element

class Solution {
public:
    int countCompleteSubarrays(vector<int> &nums) {
        unordered_set<int> distinctElements(nums.begin(), nums.end());
        int n = nums.size();
        int numberOfDistinctNumbers = distinctElements.size();
        int answer = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> seen;
            for (int j = i; j < n; j++) {
                seen.insert(nums[j]);
                if (seen.size() == numberOfDistinctNumbers) {
                    answer += (n - j);
                    break;
                }
            }

        }
        return answer;
    }
};
//==========================================================2) Second Solution ===========================================================
// TimeComplexity: O(n)
// SpaceComplexity: O(k)

class Solution {
public:
    int countCompleteSubarrays(vector<int> &nums) {
        unordered_set<int> allDistinctElements(nums.begin(), nums.end());
        unordered_map<int, int> freq;
        int n = nums.size();
        int numberOfDistinctNumbers = allDistinctElements.size();
        int answer = 0;
        int distinctNumbersInWindow = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            if (freq[nums[i]] == 1) {
                distinctNumbersInWindow++;
            }
            while (distinctNumbersInWindow == numberOfDistinctNumbers) {
                answer += n - i;
                freq[nums[j]]--;
                if (!freq[nums[j]]) {
                    distinctNumbersInWindow--;
                }
                j++;
            }

        }
        return answer;
    }
};
