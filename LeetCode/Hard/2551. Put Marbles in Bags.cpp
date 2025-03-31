class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if (k == weights.size() || k == 1) return 0;
        
        multiset<int> st;
        for (int i = 0; i < weights.size() - 1; i++) {
            st.insert(weights[i] + weights[i + 1]);
        }
        
        long long score = 0;
        
        auto rit = st.rbegin();
        for (int j = 1; j < k  && rit != st.rend(); j++, ++rit) {
            score += *rit;
        }
        
        auto it = st.begin();
        for (int i = 1; i < k  && it != st.end(); i++, ++it) {
            score -= *it;
        }
        
        return score;
    }
};
//======================================================================================================================================
// Link  : https://leetcode.com/problems/put-marbles-in-bags/
// TimeComplexity  : O(n log n)
// SpaceComplexity : O(n)
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1 || k == n) return 0;

        vector<int> pairs(n - 1);
        for (int i = 0; i < n - 1; i++) {
            pairs[i] = weights[i] + weights[i + 1];
        }

        sort(pairs.begin(), pairs.end());

        long long answer = 0;
        
        for (int i = 0; i < k - 1; i++) {
            answer -= pairs[i];
            answer += pairs[n- i - 2];
        }
        return answer;
    }
};
