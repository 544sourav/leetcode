class LRUCache {
public:
    unordered_map<int, int> mp;         
    unordered_map<int, int> key_rank;   
    map<int, int> rank_key;             
    int cap;
    int rank = 0;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        int oldRank = key_rank[key];
        rank_key.erase(oldRank);
        rank++;
        key_rank[key] = rank;
        rank_key[rank] = key;
        
        return mp[key];
    }
    
    void put(int key, int value) {
        
        if (mp.find(key) != mp.end()) {
            int oldRank = key_rank[key];
            rank_key.erase(oldRank);
        }
      
        else if (mp.size() == cap) {
            auto lru = rank_key.begin();  
            int lruKey = lru->second;
            rank_key.erase(lru);
            key_rank.erase(lruKey);
            mp.erase(lruKey);
        }

        mp[key] = value;
        rank++;
        key_rank[key] = rank;
        rank_key[rank] = key;
    }
};
