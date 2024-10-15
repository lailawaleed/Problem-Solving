//Link : https://leetcode.com/problems/separate-black-and-white-balls/

//Time Complexity : O(NlogN)
//Space Complexity : O(N)

class Solution {
public:
    long long minimumSteps(string s)
    {
        int n = s.size();
        long long count = 0;
        set<int> zeroIndices;
        int r = n - 1;
        int l = n - 2;

        while (l >= 0) {
            if (s[r] == '1') {
                l--;
                r--;
                continue;
            }

            if (s[r] == '0' && s[l] == '1' && zeroIndices.empty())
            {
                // Case 1: Direct swap when encountering "10", and no previous zeros
                swap(s[r], s[l]);
                zeroIndices.insert(l);
                count += 1;
            }
            else if (s[l] == '1' && s[r] == '0')
            {
                // Case 2: Swap with the closest tracked zero from set
                int lastIdx = *zeroIndices.rbegin();  // Get the farthest zero index
                swap(s[l], s[lastIdx]);
                zeroIndices.insert(l);
                zeroIndices.erase(--zeroIndices.end());
                count += lastIdx - l;
            }
            else
            {
                // Case 3: Insert indices of the zeroes into the set
                zeroIndices.insert(r);
                zeroIndices.insert(l);
            }

            r--;
            l--;
        }

        return count;
    }
};

//--------------------------------------------------------------Another Solution--------------------------------------------------------

//Time Complexity : O(N)
//Space Complexity : O(1)
class Solution {
public:
    long long minimumSteps(string s) {
        long long swap = 0;
        int black = 0; 
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') 
                swap += (long long) black; 
            else
                black++; 
        }
        return swap;
    }
};
