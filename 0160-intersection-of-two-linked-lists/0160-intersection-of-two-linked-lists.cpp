/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> visit;
        for(auto cur=headA;cur;cur=cur->next)
            visit.insert(cur);
        for(auto cur=headB;cur;cur=cur->next) {
            if(visit.find(cur)!=visit.end())
                return cur;
        }
        return nullptr;
    }
};