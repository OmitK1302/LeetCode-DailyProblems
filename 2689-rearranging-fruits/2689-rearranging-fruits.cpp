class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> freq;

        for (int x : basket1) freq[x]++;
        for (int x : basket2) freq[x]--;

        vector<int> excess;

        for (auto& [num, count] : freq) {
            if (count % 2 != 0) return -1;
            int half = abs(count) / 2;
            for (int i = 0; i < half; ++i)
                excess.push_back(num);
        }
        if (excess.empty()) return 0;

        sort(excess.begin(), excess.end());

        int minVal = min(*min_element(basket1.begin(), basket1.end()),
                         *min_element(basket2.begin(), basket2.end()));

        long long cost = 0;
        int n = excess.size();

        for (int i = 0; i < n / 2; ++i) {
            cost += min(excess[i], 2 * minVal);
        }

        return cost;
    }
};
