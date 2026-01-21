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
    ListNode* partition(ListNode* head, int x) {
        vector<int> b,a;
        for(auto it=head;it;it=it->next){
            if(it->val<x)
                b.push_back(it->val);
            else
                a.push_back(it->val);
        }
        auto it=head;
        for(int n:b){
            it->val=n;
            it=it->next;
        }
        for(int n:a){
            it->val=n;
            it=it->next;
        }
        return head;
    }
};