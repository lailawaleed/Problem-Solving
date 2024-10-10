//Link : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

//TimeComplexity : O(N)
//SpaceComplexity : O(N)
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for(char c:s){
            if(!st.empty()&&c==')'&&st.top()=='('){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        return st.size();
    }
};
