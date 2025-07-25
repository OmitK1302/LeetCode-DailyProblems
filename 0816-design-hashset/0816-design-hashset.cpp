class MyHashSet {
public:
    // unordered_map<int, int>map;
    vector<int>map;
    MyHashSet() {
        
    }
    
    void add(int key) {
        map.push_back(key);
    }
    
    void remove(int key) {
        for(int i = 0; i < map.size(); i++) {
            if(map[i] == key) {
                map[i] = -1;
            }
        }
    }
    
    bool contains(int key) {
        for(int i = 0; i < map.size(); i++) {
            if(map[i] == key) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */