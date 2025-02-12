//Link : https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
//Time Complexity : O(N∗N)
//Space Complexity : O(1)
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pos = s.find(part);
        while (pos != string::npos) {
            s.erase(pos, part.length());
            pos = s.find(part);
        }
        return s;
    }
};
// ------------------------------------------------------- 2) Second Solution --------------------------------------------------------------
//Time Complexity :  O(N∗M) m:partSize
//Space Complexity : O(1)
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int partLength = part.size();
        string result;
        
        for (char ch : s) {
            result.push_back(ch);
            if (result.size() >= partLength && result.substr(result.size() - partLength) == part) {
                result.erase(result.size() - partLength);
            }
        }
        return result;
    }
};

// ------------------------------------------------------- 3) Third Solution --------------------------------------------------------------
//Time Complexity :  O(N+M) m:partSize
//Space Complexity : O(N)
class Solution {
public:
    // Knuth-Morris-Pratt (KMP) algorithm
    int longestPrefixSuffix[1001] = {0};

    void computeLPSArray(string pattern) {
        int length = 0;
        for (int i = 1; i < pattern.size(); i++) {
            while (length && (pattern[i] != pattern[length])) {
                length = longestPrefixSuffix[length - 1];
            }
            if (pattern[i] == pattern[length]) {
                length++;
            }
            longestPrefixSuffix[i] = length;
        }
    }

    string removeOccurrences(string s, string part) {
        int partLength = part.size();
        computeLPSArray(part);
        string result;
        vector<int> prefixIndices;
        int length = 0;

        for (char ch: s) {
            result.push_back(ch);
            prefixIndices.push_back(length);
            while (length && (ch != part[length])) {
                length = longestPrefixSuffix[length - 1];
            }
            if (ch == part[length]) {
                length++;
            }
            prefixIndices.back() = length;
            if (length == partLength) {
                result.resize(result.size() - length);
                prefixIndices.resize(prefixIndices.size() - length);
                length = prefixIndices.empty() ? 0 : prefixIndices.back();
            }
        }
        return result;
    }
};
