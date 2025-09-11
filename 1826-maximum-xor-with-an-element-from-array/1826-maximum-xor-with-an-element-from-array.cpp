class TrieNode {
public:
    vector<TrieNode*>children;
    bool isEnd;

    TrieNode() {
        children.resize(2);
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(int val) {
        TrieNode* curr = root;
        for(int i = 31; i >= 0; i--) {
            int currBit = (val & (1 << i)) == 0 ? 0 : 1;
            
            if(curr -> children[currBit]) {
                curr = curr -> children[currBit];
            }
            else{
                curr -> children[currBit] = new TrieNode();
                curr = curr -> children[currBit];
            }
        }

        curr -> isEnd = true;
    }

    int search(int val) {
        TrieNode* curr = root;
        int res = 0;
        for(int i = 31; i >= 0; i--) {
            int currBit = (val & (1 << i)) == 0 ? 0 : 1;
            
            if(curr -> children[(!currBit)]) {
                curr = curr -> children[(!currBit)];
                res |= (1 << i);
            }
            else{
                curr = curr -> children[currBit];
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>res(queries.size());
        sort(nums.begin(), nums.end());

        Trie* root = new Trie();

        vector<pair<int, pair<int, int>>> newQrs;
        for(int i = 0; i < queries.size(); i++) {
            auto que = queries[i];
            // cout<<que[0]<<" "<<que[1]<<endl;
            newQrs.push_back({que[1], {que[0], i}});
        }

        // cout<<endl;

        sort(newQrs.begin(), newQrs.end());
        // for(auto& it : newQrs) {
        //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
        // }



        int i = 0;
        while(newQrs[i].first < nums[0]) {
            res[newQrs[i].second.second] = -1;
            i++;
        }

        

        for(auto& it : nums) {
            if(i == newQrs.size()) {
                return res;
            }
            if(it <= newQrs[i].first) {
                root -> insert(it);
            }
            while(i < newQrs.size() && newQrs[i].first < it) {
                res[newQrs[i].second.second] = root -> search(newQrs[i].second.first);
                i++;
            }
            root -> insert(it);
        }

        while(i < newQrs.size()) {
            res[newQrs[i].second.second] = root -> search(newQrs[i].second.first);
            i++;
        }

        return res;
    }
};