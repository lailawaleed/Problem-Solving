//Link :  https://leetcode.com/problems/count-total-number-of-colored-cells/description/
// Time Complexity : O(n) 
// Space Complexity: O(n) 
class Solution {
public:
    long long solve(int n) {
        if (n == 1) {
            return n+(n-1)*4;
        }
        return (n-1)*4 + solve(n-1);
    }

    long long coloredCells(int n) {
        long long result = solve(n);
        return result;
    }
};
//------------------------------------------------------- 2)Second Solution -------------------------------------------------------------
// Time Complexity : O(n) 
// Space Complexity: O(n) 
class Solution {
public:
    long long dp[100001]; 
    long long solve(int n) {
        if (n == 1) {
            return n + (n - 1) * 4;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = (n - 1) * 4 + solve(n - 1);
    }

    long long coloredCells(int n) {
        memset(dp, -1, sizeof(dp)); 
        long long result = solve(n);
        return result;
    }
};
//------------------------------------------------------- 3)Third Solution -------------------------------------------------------------
// Time Complexity : O(n) 
// Space Complexity: O(1) 
class Solution {
public:
    long long coloredCells(int n) {
        long long result = 1;
        for (int i = 2; i <= n; i++) {
            result += (i - 1) * 4;
        }
        return result;
    }
};
//------------------------------------------------------- 4)Fourth Solution -------------------------------------------------------------
// Time Complexity : O(1) 
// Space Complexity: O(1) 
class Solution {
public:
    long long coloredCells(int n) {
        return 1LL + 4LL * n * (n - 1) / 2;
    }
};
