class ProductOfNumbers {
public:
    vector<int> values;
    
    ProductOfNumbers() {
        values = {};
    }
    
    void add(int num) {
        values.push_back(num);
    }
    
    int getProduct(int k) {
        if (k > values.size()) return 0;

        int val = 1;
        for (int i = values.size() - 1; i >= int(values.size()) - k; i--) {
            val *= values[i];
        }

        return val;
    }
};
