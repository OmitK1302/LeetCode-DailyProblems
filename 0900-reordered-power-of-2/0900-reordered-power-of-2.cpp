class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<string>powerOf2 = { "1", "2", "4", "8", "16", "23", "46", "128", "256", "125",
            "0124", "0248", "0469", "1289", "13468", "23678", "35566",
            "011237", "122446", "224588", "0145678", "0122579", 
            "0134449", "0368888", "11266777", "23334455", "01466788",
            "112234778", "234455668", "012356789", "0112344778",
            "1234446788", "2244667999", "2345588999" };

        string temp = to_string(n);
        sort(temp.begin(), temp.end());
        
        if(find(powerOf2.begin(), powerOf2.end(), temp) != powerOf2.end()) return true;
        return false;
    }



    // bool helper(string& curr, string& num) {
    //     if(curr.length() == num.length()) {
    //         if(__builtin_popcount(stoi(curr)) == 1) return true;
    //         return false;
    //     }

    //     bool res;
    //     for(int i = 0; i < num.length(); i++) {
    //         if(curr.size() == 0 && num[i] == '0') continue;

    //         if(num[i] != 'a') {
    //             curr.push_back(num[i]);
    //             char temp = num[i];
    //             num[i] = 'a';
    //             res =  helper(curr, num);
    //             curr.pop_back();
    //             num[i] = temp;
    //             cout<<curr<<" "<<num<<endl;
    //         }

    //         if(res) return true;
    //     }

    //     return false;
    // }

    // bool reorderedPowerOf2(int n) {
    //     string str = to_string(n);
    //     string curr = "";

    //     return helper(curr, str);
    //     // int maxVal = 1 << n;
    // }
};