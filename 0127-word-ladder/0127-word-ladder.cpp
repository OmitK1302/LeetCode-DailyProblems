class Solution {
public:
    bool check(string& str, string& word) {
        int cnt = 0;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] != word[i]) {
                cnt++;
            }
        }

        return cnt == 1;
    }

    int helper(string currWrd, string endWrd, unordered_map<string, vector<string>>& mp, unordered_map<string, bool>& visited) {
        queue<string>que;
        que.push(currWrd);
        visited[currWrd] = true;
        int res = 0;
        while(!que.empty()) {
            int n = que.size();

            res++;
            for(int i = 0; i < n; i++) {
                string curr = que.front();
                if(curr == endWrd) return res;
                que.pop();

                for(auto& it : mp[curr]) {
                    if(!visited[it]) {
                        que.push(it);
                        visited[it] = true;
                    }
                }
            }
        }

        return 0;
    }


    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {



        unordered_map<string, vector<string>>mp;
        unordered_map<string, bool>visited;

        for(int i = 0; i <= wordList.size(); i++) {
            string str = (i == 0) ? beginWord : wordList[i-1];
            visited[str] = false;
            for(string& curr : wordList) {
                if(check(curr, str)) {
                    mp[str].push_back(curr);
                }
            }
        }
        int res = helper(beginWord, endWord, mp, visited);

        return res;


    }
};