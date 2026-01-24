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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur=head,*prev=nullptr;
        //ios_base::sync_with_stdio(0);
        //cin.tie(nullptr);
        set<int> dup;
        while(cur){
            if(prev && cur->val==prev->val){
                dup.insert(prev->val);
                prev->next=cur->next;
                ListNode *tmp=cur;
                delete tmp;
            }
            else
                prev=cur;
            cur=prev->next;
        }
        cur=head; prev=nullptr;
        while(cur){
            if(dup.count(cur->val)){
                if(prev)
                    prev->next=cur->next;
                else
                    head=cur->next;
                dup.erase(cur->val);
                ListNode *tmp=cur;
                delete tmp;
            }
            else
                prev=cur;
            cur=prev?prev->next:head;
        }
        return head;
    }
};