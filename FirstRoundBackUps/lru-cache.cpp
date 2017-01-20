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
        if (tm.find(key) != tm.end()) { 
            int old_time = tm[key];
            int new_time = ++timer;
            tm[key] = new_time;
            mp.erase(old_time);
            mp[new_time] = Node(key, value);

        } else {
            
            if (mp.size() == maxer) { 
                auto timekey = mp.begin() -> first;
                tm.erase(mp.begin()->second.key);
                 mp.erase(timekey);
            }

            
            ++timer;
            int new_time = timer;
            mp[new_time] = Node(key, value);
            tm[key] = new_time;
        }

    }

    int timer;
    int maxer;
    
    map<int,Node> mp; 
    map<int, int> tm; 
};
