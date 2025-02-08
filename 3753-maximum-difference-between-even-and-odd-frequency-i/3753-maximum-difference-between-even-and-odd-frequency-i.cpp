class Solution {
public:
    int maxDifference(string s) {
        int minOdd = INT_MAX;
        int maxOdd = INT_MIN;;
        int minEven = INT_MAX;
        int maxEven = INT_MIN;

        unordered_map<char, int>map;
        for(char& ch: s){
            map[ch]++;
        }

        for(auto& i : map){
            int freq = i.second;

            if(freq % 2 == 0){
                minEven = min(minEven, freq);
                maxEven = max(maxEven, freq);
            }

            else{
                minOdd = min(minOdd, freq);
                maxOdd = max(maxOdd, freq);
            }
        }

        return max((maxOdd - minEven), (minOdd - maxEven));
    }
};