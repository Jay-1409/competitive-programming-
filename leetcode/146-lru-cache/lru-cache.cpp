class LRUCache {
public:
    struct Node{
        int key, val;
        Node *next, *prev;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            next = nullptr;
            prev = nullptr;
        }
    };
    int cap;
    unordered_map<int, Node*> mp;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    LRUCache(int capacity) {
        cap = capacity;
        head->prev = tail;
        tail->next = head;
    }
    void insrtN(Node* node) {
        Node* temp = head->prev;
        head->prev = node;
        node->next = head;
        node->prev = temp;
        temp->next = node;
    }
    void delN(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node* reqN = mp[key];
            delN(reqN);
            insrtN(reqN);
            return reqN->val;
        } 
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            // present
            Node* reqN = mp[key];
            reqN->val = value;
            delN(reqN);
            insrtN(reqN);
        } else {
            Node* temp = new Node(key, value);
            if(mp.size() == cap) {
                Node* lruN = tail->next;
                mp.erase(lruN->key);
                delN(lruN);
                insrtN(temp);
                mp[key] = temp;
                delete lruN;
            } else {
                insrtN(temp);
                mp[key] = temp;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */