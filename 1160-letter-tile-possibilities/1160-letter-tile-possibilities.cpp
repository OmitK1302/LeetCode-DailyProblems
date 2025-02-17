class Solution {
public:
    set<string>st;
    void findSeq(string currStr, int currIndx, unordered_map<char, int>& map){

        if(currIndx == currStr.length()){
            st.insert(currStr);
            return;
        }

        for(auto& i : map){

            if(i.second != 0){
                currStr[currIndx] = i.first;
                unordered_map<char, int>tempMap = map;
                tempMap[i.first] -= 1;
                
                findSeq(currStr, currIndx + 1, tempMap);
            }
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_map<char,int>map;
        for(char& ch : tiles){
            map[ch]++;
        }

        int res = 0;

        for(int i = 1; i <= tiles.size(); i++){
            string currStr(i, '0');
            findSeq(currStr, 0, map);
            res += int(st.size());

            st = {};
        }

        return res;
        
    }
};