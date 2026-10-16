class LFUCache {
private:
    struct Node {
        int key;
        int val;
        int freq;
        Node* next;
        Node* prev;
        Node(int k, int v): key(k), val(v), freq(1), next(nullptr), prev(nullptr) {}
    };

    int cap;
    int minfreq;
    std::unordered_map<int, Node*> keyNode;              // key -> Node*
    std::unordered_map<int, std::pair<Node*, Node*>> freqList; // freq -> {head, tail}

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = nullptr;
        node->next = nullptr;
    }

    void addNodeToFreqList(int freq, Node* node) {
        if (freqList.find(freq) == freqList.end()) {
            Node* head = new Node(-1, -1);
            Node* tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            freqList[freq] = {head, tail};
        }
        Node* head = freqList[freq].first;
        Node* nextNode = head->next;
        
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }

    void updateFreq(Node* node) {
        int freq = node->freq;
        removeNode(node);
        
        // If the current freq list is empty and was minfreq, increment minfreq
        if (freq == minfreq && freqList[freq].first->next == freqList[freq].second) {
            minfreq++;
        }
        
        node->freq++;
        addNodeToFreqList(node->freq, node);
    }

public:
    LFUCache(int capacity) : cap(capacity), minfreq(0) {}

    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) {
            return -1;
        }
        Node* node = keyNode[key];
        updateFreq(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cap <= 0) return;

        // If key already exists, update value and frequency
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->val = value;
            updateFreq(node);
            return;
        }

        // If at capacity, evict the least frequently used (and least recently used) item
        if (keyNode.size() >= cap) {
            Node* tail = freqList[minfreq].second;
            Node* lfuNode = tail->prev;
            removeNode(lfuNode);
            keyNode.erase(lfuNode->key);
            delete lfuNode;
        }

        // Insert new node with frequency 1
        Node* newNode = new Node(key, value);
        minfreq = 1;
        addNodeToFreqList(1, newNode);
        keyNode[key] = newNode;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */