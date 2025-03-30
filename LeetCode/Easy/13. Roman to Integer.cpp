//Link : https://leetcode.com/problems/roman-to-integer/
//TimeComplexity : O(n)
//SpaceComplexity  O(1)
class Solution {
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> romanToInt = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        };
        int total = romanToInt[s[s.size()-1]];
        int prevValue = romanToInt[s[0]];
        for (int i = 1; i < s.size();i++) {
            int currentValue = romanToInt[s[i]];
            if (currentValue <= prevValue) {
                total += prevValue;
            }
            else
            {
                total -= prevValue;
            }
            prevValue = currentValue;
        }
        return total;
    }
};
