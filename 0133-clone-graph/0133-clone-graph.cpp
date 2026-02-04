/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int, Node*> v;
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        if(v.find(node->val)!=v.end())
            return node;
        auto ptr=new Node(node->val);
        v[node->val]=ptr;
        for(auto itr:node->neighbors) {
            if(itr) {
                if(!v.count(itr->val))
                    ptr->neighbors.push_back(cloneGraph(itr));
                else
                    ptr->neighbors.push_back(v[itr->val]);
            }
            else
                ptr->neighbors.push_back(nullptr);
        }
        return ptr;
    }
};