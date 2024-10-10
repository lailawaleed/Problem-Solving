//Link : https://leetcode.com/problems/maximum-width-ramp/

//Time Complexity:NlogN
//Space Complexity:N
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int, int>> v(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            v[i] = {nums[i], i};
        }
        sort(v.begin(), v.end());
        int minIdx = 5e4, maxWidth=0;
        for (int i = 0; i < nums.size(); i++) {
            int currIdx = v[i].second;
            minIdx = min(minIdx, currIdx);
            maxWidth = max(maxWidth, currIdx-minIdx);
        }
        return maxWidth;
    }
};
