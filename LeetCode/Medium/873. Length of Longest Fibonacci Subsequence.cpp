//Link: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/
//TimeComplexity : O(N^2LogN)
//SpaceComplexity :O(N)
class Solution {
public:
    int lenLongestFibSubseq(vector<int> &arr) {
        unordered_map<int, int> idx;
        for (int i = 0; i < arr.size(); i++) {
            idx[arr[i]] = i;
        }
        int answer = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int x = arr[i];
                int y = arr[j];
                int length = 2;
                while (idx.find(x + y)!=idx.end()) {
                    int z = x + y;
                    x = y;
                    y = z;
                    length++;
                }
                answer = max(answer, length);
            }
        }
        return answer > 2 ? answer : 0;
    }
};
//---------------------------------------------------------2) Second Solution ------------------------------------------------------------
//TimeComplexity : O(N^2)
//SpaceComplexity :O(N)
class Solution {
public:
    int memorize[1002][1002];
    int lenLongestFibSubseq(vector<int> &arr) {
        unordered_map<int, int> idx;
        for (int i = 0; i < arr.size(); i++) {
            idx[arr[i]] = i;
        }
        int answer = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (idx.find(arr[i] + arr[j])!=idx.end()) {
                    int nextIdx=idx[arr[i] + arr[j]];
                    memorize[j][nextIdx]=memorize[i][j]+1;
                    answer = max(answer, memorize[j][nextIdx]);
                }
            }
        }
        return answer  ? answer+2 : 0;
    }
};
