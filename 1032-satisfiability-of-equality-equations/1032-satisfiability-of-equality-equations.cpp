class Solution {
public:
    char find(char c, unordered_map<char, char>& leaders) {
        if(leaders[c] == c) {
            return c;
        }

        return leaders[c] = find(leaders[c], leaders);
    }

    void Union(char c, char d, unordered_map<char, char>& leaders, unordered_map<char, int>& rank) {
        char c_lead = find(c, leaders);
        char d_lead = find(d, leaders);

        if(c_lead == d_lead) return;

        if(rank[c_lead] > rank[d_lead]) {
            leaders[d_lead] = c_lead;
        }

        else if(rank[d_lead] > rank[c_lead]) {
            leaders[c_lead] = d_lead;
        }

        else{
            leaders[c_lead] = d_lead;
            rank[d_lead] += 1;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        unordered_map<char, int>rank;
        unordered_map<char, char>leaders;

        for(int i = 0; i < 26; i++) {
            leaders['a' + i] = 'a' + i;
        }

        for(string& str : equations) {
            if(str[1] == '=') {
                Union(str[0], str[3], leaders, rank);
            }
        }

        for(string& str : equations) {
            if(str[1] == '!') {
                char ch1 = find(str[0], leaders);
                char ch2 = find(str[3], leaders);

                if(ch1 == ch2) return false;
            }
        }
        return true;
    }

};