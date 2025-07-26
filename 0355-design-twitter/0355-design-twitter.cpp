class Twitter {
public:
    vector<pair<int, int>>tweets;
    // unordered_map<pair<int, int>, bool>followers;
    vector<vector<bool>>followers;

    Twitter() {
        followers.resize(501, vector<bool>(501, false));
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int k = 0;
        int i = tweets.size() - 1;
        vector<int>res;
        while(k < 10 && i >= 0) {
            // if(followers[{userId, tweets[i].first}]) {
            //     res.push_back(tweets[i].second);
            // }
            if(followers[userId][tweets[i].first] || userId == tweets[i].first) {
                res.push_back(tweets[i].second);
                k++;
            }
            i--;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        // followers[{followerId, followeeId}] = true;
        followers[followerId][followeeId] = true;
    }
    
    void unfollow(int followerId, int followeeId) {
        // followers[{followerId, followeeId}] = false;
        followers[followerId][followeeId] = false;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */