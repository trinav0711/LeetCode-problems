class Trie {
private:
    struct Node {
        bool isEnd;
        Node* arr[26];

        Node() {
            isEnd=false;
            for(int i=0;i<26;++i)
                arr[i]=nullptr;
        }
    };
    
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur=root;
        for(char c:word) {
            if(cur->arr[c-'a']==nullptr)
                cur->arr[c-'a'] = new Node();
            cur=cur->arr[c-'a'];
        }
        cur->isEnd=true;
    }
    
    bool search(string word) {
        Node* cur=root;
        for(char c:word) {
            if(cur->arr[c-'a']==nullptr)
                return false;
            cur=cur->arr[c-'a'];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* cur=root;
        for(char c:prefix) {
            if(cur->arr[c-'a']==nullptr)
                return false;
            cur=cur->arr[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */