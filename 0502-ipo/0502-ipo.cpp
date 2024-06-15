class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // unordered_map<int, int>map;
        vector<pair<int, int>>vec(profits.size());

        for(int i = 0; i < capital.size(); i++){
            // map[capital[i]] = max(map[capital[i]], profits[i]);
            vec[i] = {capital[i], profits[i]};
        }
        sort(vec.begin(), vec.end());
        int i = 0;

        priority_queue<int>pq;

        while(k--){
            while(i < profits.size() && vec[i].first <= w){
                pq.push(vec[i].second);
                i++;
            }

            if(pq.empty()){
                break;
            }

            w += pq.top();
            pq.pop();
        }

        return w;

    }
};