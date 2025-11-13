class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 0;
        while(!st.empty() && st.top().first <= price) {
            auto currVal = st.top().second;
            st.pop();

            res += currVal;
        }

        st.push({price, res + 1});
        return res + 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */