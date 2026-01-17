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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int idx;
        ListNode *cur=head, *prev=nullptr;
        for(idx=1;idx<left;idx++){
            prev=cur;
            cur=cur->next;
        }
        ListNode *start=prev;
        ListNode *l=cur;
        ListNode *tmp;
        for(idx;idx<=right;idx++){
            tmp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=tmp;
        }
        l->next = cur;
        if(start)
            start->next=prev;
        else
            head = prev;
        return head;
    }
};