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
    // int helper(string currWrd, string endWrd, vector<string>& wordList) {
    //     if(currWrd == endWrd) return 1;
    //     int currVal = INT_MAX;
    //     for(int i = 0; i < wordList.size(); i++) {
    //         string str = wordList[i];
    //         if(wordList[i] != "-1" && check(str, currWrd)) {
    //             wordList[i] = "-1";
    //             currVal = min(currVal, helper(str, endWrd, wordList));
    //             wordList[i] = str;
    //         }
    //     }

    //     return (currVal == INT_MAX) ? INT_MAX : currVal + 1;
    // }

    int helper(string currWrd, string endWrd, unordered_map<string, vector<string>>& mp, unordered_map<string, bool>& visited) {
        queue<string>que;
        que.push(currWrd);
        // vector<bool>visited(mp.size(), false);
        visited[currWrd] = true;
        int res = 0;
        while(!que.empty()) {
            int n = que.size();

            res++;
            cout<<res;
            for(int i = 0; i < n; i++) {
                string curr = que.front();
                // que.pop();
                if(curr == endWrd) return res;
                cout<<curr<<": ";
                que.pop();

                for(auto& it : mp[curr]) {
                    if(!visited[it]) {
                        cout<<it<<" ";
                        que.push(it);
                        visited[it] = true;
                    }
                }
                cout<<endl;
            }
        }

        return 0;
    }


    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // int res = helper(beginWord, endWord, wordList, visited);
        // if(res == INT_MAX)return 0;
        // return res;



        unordered_map<string, vector<string>>mp;
        unordered_map<string, bool>visited;

        for(int i = 0; i <= wordList.size(); i++) {
            string str = (i == 0) ? beginWord : wordList[i-1];
            visited[str] = false;
            // cout<<str<<": ";
            for(string& curr : wordList) {
                if(check(curr, str)) {
                    // cout<<curr<<" ";
                    mp[str].push_back(curr);
                    // mp[str].push_back(curr);
                }
            }
            // cout<<endl;
        }


        // for(auto& it : mp) {
        //     // cout<<it.first<<": "<<it.second;
        //     cout<<it.first<<": ";
        //     for(auto& i : it.second) {
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        int res = helper(beginWord, endWord, mp, visited);

        return res;


    }
};