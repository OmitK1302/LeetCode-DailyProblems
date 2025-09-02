class TrieNode {
    public:
    unordered_map<char, TrieNode*>children;
    bool isEnd;

    TrieNode() {
        this -> isEnd = false;
    }
};

class Trie {
    public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for(char& ch : word) {
            if(!(curr -> children.count(ch))) {
                curr -> children[ch] = new TrieNode();
            }

            curr = curr -> children[ch];
        }

        curr -> isEnd = true;
    }

    bool search(string str) {
        TrieNode* curr = root;
        for(auto& it : str) {
            if(!(curr -> children.count(it))) {
                return false;
            }
            curr = curr -> children[it];
        }

        return curr -> isEnd;
    }
};

class Solution {
public:
    bool helper(int indx, string s, Trie* root, vector<int>&dp) {
        if(indx == s.size()) {
            return true;
        }

        if(dp[indx] != -1) return dp[indx];

        string str;
        for(int i = indx; i < s.size(); i++) {
            str += s[i];
            if(root -> search(str) && helper(i + 1, s, root, dp)) {
                return dp[indx] = 1;
            }
        }

        return dp[indx] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int>dp(n, -1);

        Trie* root = new Trie();
        for(auto& it : wordDict) {
            root -> insert(it);
        }

        return helper(0, s, root, dp);

    }
};

// class Solution {
// public:
//     bool helper(int indx, string s, Trie* root, vector<int>& dp) {
//         if (indx == s.size()) {
//             return true;
//         }

//         if (dp[indx] != -1) return dp[indx];

//         string str;
//         for (int i = indx; i < s.size(); i++) {
//             str += s[i];
//             if (root->search(str) && helper(i + 1, s, root, dp)) {
//                 return dp[indx] = 1;
//             }
//         }

//         return dp[indx] = 0;
//     }

//     bool wordBreak(string s, vector<string>& wordDict) {
//         int n = s.length();
//         vector<int> dp(n, -1);

//         Trie* root = new Trie();
//         for (auto& it : wordDict) {
//             root->insert(it);
//         }

//         return helper(0, s, root, dp);
//     }
// };