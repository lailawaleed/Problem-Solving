//Link : https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/
//TimeComplexity : O(2^log3(N))
//SpaceComplexity : O(2^log3(N))
class Solution {
public:
    bool solve(int p, int n) {
        // Base case: if n is 0, we've found a representation
        if (!n) return true;
        // If p < 0 or n < 0, we can't form n with the given powers of three
        if (p < 0 || n < 0) return false;

        return solve(p - 1, n - pow(3, p)) || solve(p - 1, n);
    }

    bool checkPowersOfThree(int n) {
        return solve(15, n);
    }
};

//-------------------------------------------------------- 2)Second Solution -------------------------------------------------------------
//TimeComplexity : 𝑂(log3(𝑛))
//SpaceComplexity : O(1)
class Solution {
public:
    bool checkPowersOfThree(int n) {
    while (n > 0) {
        if (n % 3 == 2) return false;
        n /= 3;
    }
       return true;
    }
};
