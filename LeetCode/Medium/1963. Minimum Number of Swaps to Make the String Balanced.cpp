//Link: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/

//TimeComplexity : O(N)  N:length of string
class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for (char c: s) {
            if (c == ']' && !st.empty() && st.top() == '[')
                st.pop();
            else {
                st.push(c);
            }
        }
        int d=ceil(st.size()/4.0);
        return d;
    }
};
