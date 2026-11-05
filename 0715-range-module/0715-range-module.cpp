struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int val = 0;
    int lazy = -1;
};

class SegTree {

protected:
    void apply(Node* root, int val) {
        root->val = val;
        root->lazy = val;
    }

    void lazy_update(Node* root, int l, int r) {
        if (l != r && root->lazy != -1) {
            if (!root->left)
                root->left = new Node();
            if (!root->right)
                root->right = new Node();

            apply(root->left, root->lazy);
            apply(root->right, root->lazy);

            root->lazy = -1;
        }
    }

    void _update(Node* root, int l, int r, int val, int s = 0, int e = 1e9) {

        if (s > r || e < l)
            return;

        if (s >= l && e <= r) {
            apply(root, val);
            return;
        }

        lazy_update(root, s, e);

        int m = s + (e - s) / 2;

        if (l <= m) {
            if (!root->left)
                root->left = new Node();
            _update(root->left, l, r, val, s, m);
        }
        if (r > m) {
            if (!root->right)
                root->right = new Node();
            _update(root->right, l, r, val, m + 1, e);
        }

        root->val = (root->left && root->left->val == 1) &&
                    (root->right && root->right->val == 1);
    }

    bool _query(Node* root, int l, int r, int s = 0, int e = 1e9) {

        if (s > r || e < l)
            return true;

        if (!root)
            return false;

        if (s >= l && e <= r)
            return root->val == 1 ? true : false;

        if (root->lazy != -1)
            return root->lazy == 1;
            
        int m = s + (e - s) / 2;

        bool ans = true;
        if (l <= m)
            ans &= _query(root->left, l, r, s, m);
        if (r > m)
            ans &= _query(root->right, l, r, m + 1, e);

        return ans;
    }

public:
    Node* root = new Node();
    void update(int l, int r, int val) { _update(root, l, r, val); }
    bool query(int l, int r) { return _query(root, l, r); }
};

class RangeModule {
public:
    SegTree tree;
    RangeModule() {}
    
    void addRange(int left, int right) {
        tree.update(left, right - 1, 1);
    }
    
    bool queryRange(int left, int right) {
        return tree.query(left, right - 1);
    }
    
    void removeRange(int left, int right) {
        tree.update(left, right - 1, 0);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */