class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k, int v) {
        this -> key = k;
        this -> val = v;

        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*>mp;
    int sz = 0;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    LRUCache(int capacity) {
        head -> next = tail;
        tail -> prev = head;
        sz = capacity;
    }
    void insertNode(int k, int v) {
        Node* lastNode = tail -> prev;
        Node* newNode = new Node(k, v);
        lastNode -> next = newNode;
        newNode -> prev = lastNode;
        newNode -> next = tail;
        tail -> prev = newNode;
        mp[k] = newNode;
    }

    void deleteNode(int k) {
        Node* curr = mp[k];
        Node* prevNode = curr -> prev;
        Node* nextNode = curr -> next;
        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
        mp.erase(k);
    }

    
    int get(int key) {
        if(!mp.count(key)) return -1;
        int v = mp[key] -> val;
        deleteNode(key);
        insertNode(key, v);
        return v;
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            deleteNode(key);
        }
        if(mp.size() == sz) {
            mp.erase(head -> next -> key);
            head -> next = head -> next -> next;
            head -> next -> prev = head;
            // deleteNode(head -> next -> key);
            // insertNode(key, value);
        }
        // else{
            insertNode(key, value);
        // }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */