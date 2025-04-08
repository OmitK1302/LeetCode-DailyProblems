class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>map;
        for(char& ch : s) {
            map[ch]++;
        }

        vector<int>freq;
        unordered_map<int, vector<char>>map1;
        for(auto& i : map) {
            map1[i.second].push_back(i.first);
            freq.push_back(i.second);
        }

        sort(freq.rbegin(), freq.rend());

        vector<int>freqUp;
        for(int i = 0; i < freq.size() - 1; i++) {
            if(freq[i] != freq[i+1]) {
                freqUp.push_back(freq[i]);
            }
        }

        freqUp.push_back(freq[freq.size() - 1]);

        string res = "";
        for(int& num : freqUp) {
            for(char& ch : map1[num]) {
                string temp(num, ch);
                res += temp;
            }
        }

        return res;
    }
};