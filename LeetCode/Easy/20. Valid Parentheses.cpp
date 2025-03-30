//Link : https://leetcode.com/problems/valid-parentheses/description/
//TimeComplexity : O(n)
//SpaceComplexity  O(n)

class Solution {
public:
    bool isValid(std::string s) {
        stack<char> stack;
        unordered_map<char, char> mapping = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        for (char c : s) {
            if (c == ')' || c == '}' || c == ']') 
            {
                // Closing bracket
                if (stack.empty() || stack.top() != mapping[c]) {
                    return false;
                }
                stack.pop();
            } 
            else 
            {
                // Opening bracket
                stack.push(c);
            }
        }
        
        return stack.empty();
    }
};
