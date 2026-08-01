class RandomizedSet {
    vector<int> v;
    unordered_map<int, int> mp;
public:
    RandomizedSet() {
        
    }

    bool insert(int val) {
        if (mp.count(val)) {
            return false;
        }
        v.push_back(val);
        mp[val] = v.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!mp.count(val)) {
            return false;
        }

        int index = mp[val];
        int last = v.back();

        v[index] = last; 
        mp[last] = index;

        v.pop_back();
        mp.erase(val);

        return true;
    }

    int getRandom() {
        return v[rand() % v.size()];
    }
};
