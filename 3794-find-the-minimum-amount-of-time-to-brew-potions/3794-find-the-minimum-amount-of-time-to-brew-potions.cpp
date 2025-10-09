class Solution {
    long long updateTime(vector<pair<long long, long long>>& wTime, long long strtTime, vector<int>& skill, int mana) {
        // long long strtTime = 0;
        for(int i = 0; i < skill.size(); i++) {
            long long endTime = strtTime + (skill[i] * mana);
            wTime[i] = {strtTime, endTime};
            strtTime = endTime;
        }

        return strtTime;
    }

public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<pair<long long, long long>>workTime(n);

        // long long strtTime = 0;
        // for(int i = 0; i < n; i++) {
        //     long long endTime = strtTime + (skill[i] * mana[0]);
        //     workTime.push_back({strtTime, endTime});
        //     strtTime = endTime;

        //     totSkls += skill[i];
        // }

        long long totSkls = 0;
        long long strtTime = 0;
        for(auto& it : skill) {
            totSkls += it;
        }

        strtTime = updateTime(workTime, 0, skill, mana[0]);

        // for(auto& it : workTime) {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        for(int i = 1; i < m; i++) {
            long long cst = mana[i];
            for(int j = n-2; j >= 0; j--) {
                long long currTime = strtTime - (skill[j] * cst);
                // cout<<currTime<<" ";

                if(!(strtTime <= workTime[j].first || currTime >= workTime[j].second)) {
                    // cout<<"Overlap: "<<strtTime<<" "<<currTime<<" "<<workTime[j].first<<" "<<workTime[j].second<<endl; 
                    strtTime = workTime[j].second;
                }
                else{
                    strtTime = currTime;
                }
            }
            // cout<<endl<<strtTime;
            strtTime = updateTime(workTime, strtTime, skill, cst);
            // cout<<endl<<strtTime<<endl;
            // strtTime += (totSkls * cst);
        }

        return strtTime;
    }
};