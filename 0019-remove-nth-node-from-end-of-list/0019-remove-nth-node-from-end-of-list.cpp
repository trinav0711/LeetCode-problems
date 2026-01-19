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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int ctr=0;
        for(auto itr=head;itr!=nullptr;itr=itr->next)
            ctr++;
        n=ctr-n+1;
        auto it=head;
        ListNode *prev=nullptr;
        for(ctr=1;ctr<n && it!=nullptr;ctr++, it=it->next)
            prev=it;
        auto tmp=head;
        if(n==1)
            head=head->next;
        else{
            tmp=it;
            prev->next=it->next;
        }
        delete tmp;
        return head;
    }
};