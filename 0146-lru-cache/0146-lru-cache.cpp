class LRUCache {
    class Node{
        public: 
            int key;
            int val;
            Node* prev;
            Node* next;

            Node(int key, int val) : key(key), val(val) {
                prev=next=nullptr;
            }
    };

    Node* head;
    Node* tail;

    int cap;
    unordered_map<int, Node*> m;

public:
    LRUCache(int capacity): cap(capacity), head(nullptr), tail(nullptr) {}

    void addNode(Node* newnode){
        m[newnode->key]=newnode;
        if(!head) {
            head = tail = newnode;
            return;
        }
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }

    void deleteNode(Node* delnode){
        if(tail==delnode)
            tail=delnode->prev;
        else
            delnode->next->prev=delnode->prev;
        if(head==delnode)
            head=delnode->next;
        else
            delnode->prev->next=delnode->next;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        deleteNode(m[key]);
        addNode(m[key]);
        return m[key]->val;
    }
    
    void put(int key, int value) {
        Node* newnode = nullptr;
        if(m.find(key)!=m.end()) {
            newnode = m[key];
            newnode->val=value;
            deleteNode(newnode);
        }
        else {
            newnode = new Node(key, value);
            m[key]=newnode;
        }
        addNode(newnode);
        if(m.size()>cap) {
            auto cur=tail->key;
            deleteNode(tail);
            delete(m[cur]);
            m.erase(cur);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */