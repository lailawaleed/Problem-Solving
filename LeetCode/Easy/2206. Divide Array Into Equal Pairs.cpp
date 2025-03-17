//Link : https://leetcode.com/problems/divide-array-into-equal-pairs/
//Time Complexity  :  O(N)
//Space Complexity :  O(N)

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size() / 2;
        int counter = 0;
        unordered_map<int, int> mp;
        
        for(int num : nums) {
            mp[num]++;
        }
        
        for(auto p : mp) {
            counter += p.second / 2;
        }
        
        return counter == n;
    }
};
