/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        struct _cmp {
            bool operator()(ListNode* a, ListNode* b) const {
                return a->val > b->val;
            }
        };
        priority_queue<ListNode*, vector<ListNode*>, _cmp> pq;
        for(auto ptr:lists) {
            if(ptr)
                pq.push(ptr);
        }
        auto dummy = new ListNode(-1);
        auto cur=dummy;
        while(!pq.empty()) {
            cur->next=pq.top();
            cur=cur->next;
            pq.pop();
            if(cur->next)
                pq.push(cur->next);
            cur->next=nullptr;
        }
        cur=dummy->next;
        delete dummy;
        return cur;
    }
};