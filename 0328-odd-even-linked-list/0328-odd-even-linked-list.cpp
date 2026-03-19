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
    ListNode* oddEvenList(ListNode* head) {
        auto cur=head;
        ListNode *newHead=nullptr, *prev=nullptr;
        if(!cur || cur->next==nullptr)
            return head;
        prev=cur;
        cur=cur->next;
        newHead=cur;
        while(cur) {
            prev->next=cur->next;
            prev=cur;
            cur=cur->next;
        }
        cur=head;
        while(cur->next)
            cur=cur->next;
        cur->next=newHead;
        return head;
    }
};