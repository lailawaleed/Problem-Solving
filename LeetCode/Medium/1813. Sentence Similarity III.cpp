//Link : https://leetcode.com/problems/sentence-similarity-iii/
//Complexity :O(n)
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence2.size() > sentence1.size())
            swap(sentence2, sentence1);
        stringstream s(sentence1);
        stringstream s2(sentence2);
        string word;
        vector<string> se1;
        vector<string> se2;
        while (s >> word) {
            se1.push_back(word);
        }
        while (s2 >> word) {
            se2.push_back(word);
        }
        if (se1 == se2) {
            return true;
        }
        int n1=se1.size();
        int n2=se2.size();
        int left=0;
        while (left<n2 && se1[left]==se2[left]){
            left++;
        }
        int right=0;
        while (right<n2 &&se1[n1-right-1]==se2[n2-right-1]){
            right++;
        }
        return right+left>=n2;
    }
};
