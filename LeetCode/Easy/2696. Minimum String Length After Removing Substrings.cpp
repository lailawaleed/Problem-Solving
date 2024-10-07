//Link : https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/
//First Solution

//Time Complexity: O(n)
//Space Complexity: O(n)
class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(char c:s){
            if(!st.empty() && (c=='B' &&st.top()=='A' ||c=='D' &&st.top()=='C' )){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        return st.size();
    }
};


//Second Solution

//Time Complexity: O(n^2)
//Space Complexity: O(n)

class Solution {
public:
    int minLength(string s) {
        for (int i = 0; i < s.size(); i++)
        {
            string sub=s.substr(i,2);
            if(sub=="AB" || sub=="CD"){
                s.erase(i,2);
                i=-1;
            }
        }
        return s.size();
    }
};


//Third Solution

//Time Complexity: O(n)
//Space Complexity: O(n)
class Solution {
public:
    int minLength(string s)
    {
        string res="";
        for (char c: s) {
            int n = res.size();
            //AB
            if (!res.empty() &&( (res[n - 1] == 'A' && c == 'B') || (res[n - 1] == 'C' && c == 'D'))) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        return res.size();
    }
};

