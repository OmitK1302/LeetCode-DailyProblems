class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_map<string, int>map;
        sort(folder.begin(), folder.end());

        vector<string>res;
        for(string& str : folder) {
            int n = str.length();
            bool flag = false;
            // int i = 0;
            int j = 1;
            string temp = "/";
            while(j < n) {
                if(str[j] == '/') {
                    if(map.count(temp)) {
                        flag = true;
                        break;
                    }
                }
                temp += str[j++];
            }

            if(!flag) {
                map[str] = 1;
                res.push_back(str);
            }
        }

        return res;
    }
};