class TopVotedCandidate {
    unordered_map<int, int>map;
    vector<int>timesCopy;
    int lowerBnd(vector<int>& times, int k) {
        int l = 0;
        int r = times.size() - 1;

        while(l <= r) {
            int mid = l + ((r - l) / 2);

            if(times[mid] <= k) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return l-1;
    }

public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        timesCopy = times;
        int n = persons.size();
        vector<int>votes(n, 0);
        int maxVotes = 0;
        int maxVoteCand = -1;

        for(int i = 0; i < n; i++) {
            votes[persons[i]]++;
            if(votes[persons[i]] >= maxVotes) {
                maxVoteCand = persons[i];
            }
            maxVotes = max(maxVotes, votes[persons[i]]);

            map[times[i]] = maxVoteCand;
        }

        for(auto& it : map) {
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
    
    int q(int t) {
        int lb = lowerBnd(timesCopy, t);
        return map[timesCopy[lb]];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */