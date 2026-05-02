class Node {
public:
    int key, value;
    Node *prev, *next;
    Node(int k, int v): key{k}, value{v}, prev{nullptr}, next{nullptr} {}
};

class LRUCache {
private:
    int cap;
    Node *head, *tail;
    unordered_map<int, Node*> m;

    // Helper: Always inserts right after head (Most Recently Used)
    void insertAfterHead(Node* node) {
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    // Helper: Disconnects a node from its current neighbors
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int cap) : cap{cap} {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        
        Node* node = m[key];
        removeNode(node);      // Take it out of its current spot
        insertAfterHead(node); // Move it to the front
        return node->value;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            // Key exists: Update value and move to front
            Node* existing = m[key];
            existing->value = value;
            removeNode(existing);
            insertAfterHead(existing);
        } else {
            // Key is new: Check capacity first
            if (m.size() == cap) {
                Node* lru = tail->prev; // Node before tail is the Least Recently Used
                m.erase(lru->key);
                removeNode(lru);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            m[key] = newNode;
            insertAfterHead(newNode);
        }
    }
};