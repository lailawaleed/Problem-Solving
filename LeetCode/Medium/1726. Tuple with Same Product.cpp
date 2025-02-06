//Link : https://leetcode.com/problems/tuple-with-same-product/
//O(n^2)
//O(n^2)
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        //C(k, 2)
        unordered_map<int, int> mp;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int product = nums[i] * nums[j];
                mp[product]++;
            }
        }
        
        int result = 0;
        for (const auto& pair : mp) {
            if (pair.second > 1) {
                result += (pair.second * (pair.second - 1)) / 2 * 8;
            }
        }
        return result;
    }
};
