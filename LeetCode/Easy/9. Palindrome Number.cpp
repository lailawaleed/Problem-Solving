//Link : https://leetcode.com/problems/palindrome-number/
//TimeComplexity : O(log₁₀ x))
//SpaceComplexity  O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // For even digits: x == reversedHalf
        // For odd digits: x == reversedHalf / 10 (middle digit doesn't matter)
        return x == reversedHalf || x == reversedHalf / 10;
    }
};
