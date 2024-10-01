// Problem link: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> reminder(k);
        for (int i = 0; i < arr.size(); i++) 
        {
                reminder[((arr[i]%k) + k)%k]++;
        }
        if (reminder[0] % 2 != 0)
            return false;
        for (int i = 1; i <= k / 2; i++) {
            int comReminder = reminder[k - i];
            if (comReminder != reminder[i]) {
                return false;
            }
        }
        return true;
    }
};
