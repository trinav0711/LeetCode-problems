class WordDictionary {
private:
    struct Node {
        Node* arr[26];
        bool isEnd;

        Node(): isEnd{false} {
            for(int i=0;i<26;++i)
                arr[i]=nullptr;
        }
    };
    Node *root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        auto cur=root;
        for(char c:word) {
            if(!cur->arr[c-'a'])
                cur->arr[c-'a']=new Node();
            cur=cur->arr[c-'a'];
        }
        cur->isEnd=true;
    }

    bool find(string word, Node *cur) {
        if(word.empty())
            return cur->isEnd;
        char c=word.back();
        if(c!='.' && cur->arr[c-'a']==nullptr)
            return false;
        word.pop_back();
        if(c!='.')
            return find(word, cur->arr[c-'a']);
        for(int i=0;i<26;++i) {
            if(cur->arr[i] && find(word, cur->arr[i]))
                return true;
        }
        return false;
    }
    
    bool search(string word) {
        reverse(word.begin(), word.end());
        return find(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */