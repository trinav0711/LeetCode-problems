class Trie {
private:
    struct Node {
        Node* arr[26];
        bool isEnd;

        Node(): isEnd{false} {
            for(int i=0;i<sizeof(arr)/sizeof(decltype(*arr));++i)
                arr[i]=nullptr;
        }
    };

    Node* root;
    
public:
    Trie(): root{new Node()} {}
    
    void insert(string word) {
        auto itr=root;
        for(char c:word) {
            if(itr->arr[c-'a']==nullptr)
                itr->arr[c-'a'] = new Node();
            itr=itr->arr[c-'a'];
        }
        itr->isEnd=true;
    }
    
    bool search(string word, bool prefix=false) {
        auto itr=root;
        for(char c:word) {
            if(itr->arr[c-'a']==nullptr)
                return false;
            itr=itr->arr[c-'a'];
        }
        return prefix || itr->isEnd;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */