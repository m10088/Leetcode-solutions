#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
#define N 1007

#define EPS 1e-10
struct Node {
  int key;
  int val;
  Node(int key,int val):key(key), val(val) {}
  Node() {}
};
class LRUCache {
public:
    LRUCache(int capacity) {
        timer = 0;
        maxer = capacity;
        mp.clear();
        tm.clear();
    }

    int get(int key) {
        if (tm.find(key) == tm.end()) return -1;
        //getçæ¶åä¹è¦æ´æ°ç³»ç»çæ¶é´

        int time = tm[key];
        int ret = mp[time].val;

        int old_time = tm[key];
        int new_time = ++timer;

        tm[key] = new_time;
        mp.erase(old_time);
        mp[new_time] = Node(key, ret);
        return ret;

    }
    void set(int key, int value) {
        if (tm.find(key) != tm.end()) { //æ´æ°è·åçæ¶é´
            int old_time = tm[key];
            int new_time = ++timer;
            tm[key] = new_time;
            mp.erase(old_time);
            mp[new_time] = Node(key, value);

        } else {
            //ä»¥åæ²¡æè¿ä¸ªåç´ ,
            if (mp.size() == maxer) { //å¦æè¶è¿å®¹éäºï¼éè¦å é¤ææ©çé£ä¸ªåç´ 
                auto timekey = mp.begin() -> first;
                tm.erase(mp.begin()->second.key);
                 mp.erase(timekey);
            }

            //å¦ææ²¡æè¶è¿å®¹éï¼ç´æ¥å¢å è¿ä¸ªåç´ 
            ++timer;
            int new_time = timer;
            mp[new_time] = Node(key, value);
            tm[key] = new_time;
        }

    }

    int timer;
    int maxer;
    //ä¸¤ä¸ªmpåæ¶ç»´æ¤ï¼åæ¶å¢å åç´ æåå°åç´ 
    map<int,Node> mp; // time - node
    map<int, int> tm; // key - time
};
