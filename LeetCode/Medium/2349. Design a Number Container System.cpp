//Link : https://leetcode.com/problems/design-a-number-container-system/
//O(1)
//O(N)
class NumberContainers {
public:
    // Maps a number to ==> set of indices 
    unordered_map<int, set<int>> numberToIndices;
    
    // Maps an index to ===> the number it holds
    unordered_map<int, int> indexToNumber;
    
    NumberContainers() {}

    void change(int index, int number) {
        // If the index already has a number, remove the index from the old number's set
        if (indexToNumber.count(index)) {
            int oldNumber = indexToNumber[index];
            numberToIndices[oldNumber].erase(index);
        }
        // Update the index with the new number
        indexToNumber[index] = number;
        // Add the index to the new number's set
        numberToIndices[number].insert(index); 
    }


    int find(int number) {
        return numberToIndices[number].size() ? *(numberToIndices[number].begin()) : -1;
    }
};
auto init = [] {   ///Fast input & output
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index, number);
 * int param_2 = obj->find(number);
 */
