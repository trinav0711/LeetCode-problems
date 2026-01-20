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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        int idx=0;
        ListNode *prev;
        for(auto newHead=head; newHead!=nullptr; newHead=newHead->next, idx++)
            prev=newHead;
        k=k%idx;
        if(!k)
            return head;
        k=idx-k+1;
        prev->next=head;
        for(idx=1;head && idx<k;head=head->next,idx++)
            prev=head;
        prev->next=nullptr;
        return head;   
    }
};