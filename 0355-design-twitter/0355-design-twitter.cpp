class Twitter {
private:
    unordered_map<int, unordered_set<int>> m;
    unordered_map<int, queue<pair<int,int>>> news;
    int ctr;
public:
    Twitter(): m{}, news{}, ctr{1} {}
    
    void postTweet(int userId, int tweetId) {
        news[userId].push({ctr++, tweetId});
        if(news[userId].size()>10)
            news[userId].pop();
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> users;
        if(news.find(userId)!=news.end())
            users.push_back(userId);
        for(int x:m[userId]) {
            if(news.find(x)!=news.end())
                users.push_back(x);
        }
        for(int user:users) {
            int sz=news[user].size();
            while(sz--) {
                auto cur=news[user].front();
                pq.push(cur); news[user].pop();
                news[user].push(cur);
            }
            while(pq.size()>10)
                pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        m[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        m[followerId].erase(followeeId);
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