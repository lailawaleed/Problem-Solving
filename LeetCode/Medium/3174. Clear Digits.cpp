/*
  Link :https://leetcode.com/problems/clear-digits/?envType=daily-question&envId=2025-02-10
  Time Complexity :  O(N)
  Space Complexity : O(N)
*/
class Solution {
public:
    string clearDigits(string s) {
        stack<char>charStack;
        for(int i=0;i<s.size();i++){
            if(!charStack.empty() && isdigit(s[i]))){
                charStack.pop();
            }
            else{
                charStack.push(s[i]);
            }
        }
        string afterRemoval;
        afterRemoval.reserve(charStack.size());
        while (charStack.size()){
            afterRemoval.push_back(charStack.top());
            charStack.pop();
        }
        reverse(afterRemoval.begin(),afterRemoval.end());
        return afterRemoval;
    }
};
// ----------------------------------------------------------- Second Solution -----------------------------------------------------------
/*
  Time Complexity :  O(N)
  Space Complexity : O(N)
*/
class Solution {
public:
    string clearDigits( string input) {
        string charStack; 
        
        for (char ch : input) {
            if (!charStack.empty() && isdigit(ch)) {
                charStack.pop_back();
            } 
            else 
            {
                charStack.push_back(ch);
            }
        }
        return charStack;
    }
};
// ----------------------------------------------------------- Third Solution -----------------------------------------------------------
/*
  Time Complexity :  O(N)
  Space Complexity : O(1)
*/
class Solution {
public:
    string clearDigits(string s) {
        int j = 0;
        for (char ch : s) {
            j && isdigit(ch) ? j-- : s[j++] = ch;
        }
        s.resize(j);
        return s;
    }
};

/*
 TESTCASES
 - 44abc (according to problem descrition it will not happen)
*/
