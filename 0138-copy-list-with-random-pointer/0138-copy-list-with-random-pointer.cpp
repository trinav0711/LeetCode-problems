/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *cur, *newHead, *prevcur;
        prevcur=head;
        cur=newHead=nullptr;
        unordered_map<Node*, int> m1;
        unordered_map<int, Node*> m2;
        int idx = 0;
        while(prevcur!=nullptr){
            m1.emplace(prevcur, idx);
            Node* tmp = new Node(prevcur->val);
            m2.emplace(idx, tmp);
            if(newHead == nullptr){
                newHead = tmp;
                cur = newHead;
            }
            else{
                cur->next = tmp;
                cur = tmp;
            }
            prevcur = prevcur->next;
            idx++;
        }

        prevcur=head;
        cur=newHead;
        while(prevcur != nullptr){
            if(prevcur->random == nullptr)
                cur->random = nullptr;
            else
                cur->random=m2[m1[prevcur->random]];
            prevcur=prevcur->next;
            cur=cur->next;
        }
        return newHead;
    }
};