//Link : https://leetcode.com/problems/product-of-the-last-k-numbers/description/
//Time Complexity :  O(k)
//Space Complexity : O(N)
class ProductOfNumbers {
public:
    vector<int>stream;
    void add(int num) {
        stream.push_back(num);
    }

    int getProduct(int k) {
        int product=1;
        for(int i=stream.size()-k;i<stream.size();i++)
            product*=stream[i];
        return product;
    }
};
//--------------------------------------------------------------------------- 2) Second Solution ------------------------------------------------------------------------------------------
//Time Complexity :  O(1)
//Space Complexity : O(N)

class ProductOfNumbers {
public:
    vector<int> prefixProduct;
    ProductOfNumbers() {
        prefixProduct.push_back(1);  
    }

    void add(int num) {
        if (num == 0) {
            prefixProduct.clear();
            prefixProduct.push_back(1);
        } else {
            prefixProduct.push_back(prefixProduct.back() * num);
        }
    }

    int getProduct(int k) {
        int n = prefixProduct.size();
        if (k >= n) return 0;
        return prefixProduct.back() / prefixProduct[n - k - 1];
    }
};
