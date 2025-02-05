//Link : https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
//O(N)
//O(N)
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        unordered_multiset<char> st1, st2;
        for (char c : s1) {
            st1.insert(c);
        }
        for (char c : s2) {
            st2.insert(c);
        }

        if (st1 != st2) {
            return false;
        }

        int n=s1.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                count++;
            }
            if(count>2){
                return false;
            }
        }
        return true;
    }
};
