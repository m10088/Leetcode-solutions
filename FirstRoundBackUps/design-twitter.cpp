#define N 1007
struct Node {
    int id, t;
    Node(int i, int t):id(i), t(t) {}
    Node() {}
};

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        timer = 0;
        for (int i=0; i<N; i++) { v[i].clear(); fo[i].clear(); fo[i].push_back(i); }
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        v[userId].push_back(Node(tweetId, timer++));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
         for (int i=0; i<N; i++) Cur[i] = v[i].size()-1;
        
        vector<int> ret;
        for (int i=0; i<10; i++) {
            int maxer = -1;
            int selectid = -1;
            int rec = -1;
            for (int i=0; i<fo[userId].size(); i++) {
                int& k = fo[userId][i];
                if (Cur[k]<0) continue;
                if (v[k][Cur[k]].t > maxer) {
                    maxer = v[k][Cur[k]].t;
                    rec = k;
                    selectid = v[k][Cur[k]].id;
                }
            }
            if (selectid == -1) break;
            ret.push_back(selectid);
            Cur[rec]--;
        }
        return ret;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        fo[followerId].push_back(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        for (auto p = fo[followerId].begin(); p!=fo[followerId].end(); p++) {
            if ((*p)==followeeId) {
                p = fo[followerId].erase(p);
                break;
            }
        }
    }
    int timer;
    vector<Node> v[N];
    vector<int> fo[N];
    int Cur[N];
};
/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */