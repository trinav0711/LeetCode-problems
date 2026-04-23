class Solution {
private:
    struct Node {
        Node* arr[26];
        bool end;
        Node() : end(false) {
            for(int i=0;i<26;++i)
                arr[i]=nullptr;
        }
    };

    struct Trie {
        Node* root;
        Trie() : root{new Node()} {}
    };

    void insert(Node* cur, string& s) {
        for(char c:s) {
            if(!cur->arr[c-'a'])
                cur->arr[c-'a']=new Node();
            cur=cur->arr[c-'a'];
        }
        cur->end=true;
    }

    void traverse(Node* cur, vector<string>& v, string& s) {
        int i=0;
        while(i<26) {
            if(cur->arr[i]) {
                s.push_back('a'+i);
                traverse(cur->arr[i], v, s);
            }
            ++i;
        }
        if(cur->end) {
            v.push_back(s);
        }
        s.pop_back();
    }

    vector<string> search(Node* root, string c) {
        vector<string> ret;
        for(char ch: c) {
            if(!root->arr[ch-'a'])
                return {};
            root=root->arr[ch-'a'];
        }
        traverse(root, ret, c);
        sort(ret.begin(), ret.end());
        while(ret.size()>3)
            ret.pop_back();
        return ret;
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie tr;
        for(string& s:products)
            insert(tr.root, s);
        vector<vector<string>> ans;
        string str="";
        for(char c:searchWord) {
            str.push_back(c);
            ans.push_back(search(tr.root, str));
        }
        return ans;
    }
};