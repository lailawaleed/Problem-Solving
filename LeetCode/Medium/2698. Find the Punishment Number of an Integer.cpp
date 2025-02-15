//Link : https://leetcode.com/problems/find-the-punishment-number-of-an-integer/
//Time Complexity :  O(2^N)
//Space Complexity : O(1)
class Solution {
public:
    bool canSplit(const string &numStr, int target) {
        int len = numStr.size();

        /** Iterate over all possible split patterns using bitwise operations **/
        for (int mask = 0; mask < (1 << (len - 1)); mask++) {
            int sum = 0;
            int currentNum = numStr[0] - '0'; // Start with first digit

            for (int i = 0; i < len - 1; i++)
            {
                if (mask & (1 << i))
                {
                    sum += currentNum;
                    currentNum = numStr[i + 1] - '0';
                }
                else
                {
                    currentNum = currentNum * 10 + (numStr[i + 1] - '0');
                }
            }

            sum += currentNum;
            
            if (sum == target) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int square = i * i;
            string squareStr = to_string(square);
            if (canSplit(squareStr, i)) {
                ans += square;
            }
        }
        return ans;
    }
};
//-------------------------------------------------------- 2) second solution -----------------------------------------------------------
/*
  Time Complexity :   
    canSplit Function: O(2^m), where m is the number of digits in square (m = log(square)) --> m=n*n 
    punishmentNumber Function: O(n^3), as it calls canSplit for each number from 1 to n
    OverAllTime : O(n^3)
  
  Space Complexity : O(log(N))
*/
class Solution {
public:
    bool canSplit(int num, const string& square, int idx, int currentSum, int currentNum) {
        if (idx == square.size())
        {
            currentSum += currentNum;
            return currentSum == num;
        }
        
        int nextNum = currentNum * 10 + (square[idx] - '0');

        /**
         *  Option 1: Continue the current number by adding the next digit
         *  Option 2: Split here and start a new number from the current digit
         * */
        return canSplit(num, square, idx + 1, currentSum + currentNum, square[idx] - '0') ||
               canSplit(num, square, idx + 1, currentSum, nextNum);
    }

    int punishmentNumber(int n) {
        int ans = 0;
        
        for (int i = 1; i <= n; ++i) {
            int square = i * i;
            string squareStr = to_string(square);  
            
            if (canSplit(i, squareStr, 1, 0, squareStr[0] - '0')) {
                ans += square; 
            }
        }

        return ans;
    }
};
//-------------------------------------------------------- 3) Third solution -----------------------------------------------------------
