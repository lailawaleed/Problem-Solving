// TimeComplexity  : O(n)
// SpaceComplexity : O(n)
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = nums[nums[i]];
        }
        return v;
    }
};
//======================================================== 2) Second Solution =============================================================
// TimeComplexity  : O(n)
// SpaceComplexity : O(1)
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] + n * (nums[nums[i]] % n);
        }
        for (int i = 0; i < n; i++) {
            nums[i] /= n;
        }
        return nums;
    }
};
