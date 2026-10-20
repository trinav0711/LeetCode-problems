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
private:
    int gcd(const int a, const int b) const {
        int maxx=min(a,b);
        for(int i=maxx;i;--i) {
            if(a%i==0 && b%i==0)
                return i;
        }
        return 0;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head) return head;
        auto cur=head->next, prev=head;
        while(cur) {
            prev->next=new ListNode(gcd(cur->val, prev->val), cur);
            prev=cur;
            cur=cur->next;
        }
        return head;
    }
};