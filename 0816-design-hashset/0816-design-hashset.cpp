class MyHashSet {
public:
    unordered_map<int, int>map;
    MyHashSet() {
        
    }
    
    void add(int key) {
        map[key] = 1;
    }
    
    void remove(int key) {
        map.erase(key);
    }
    
    bool contains(int key) {
        return map.count(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */