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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* sumHead = nullptr;
        ListNode* cur = nullptr;
        ListNode* tmp1=l1;
        ListNode* tmp2=l2;
        while(tmp1 != nullptr || tmp2 != nullptr || carry){
            ListNode* tmp = new ListNode(carry, nullptr);
            if(tmp1 != nullptr)
                tmp->val += tmp1->val;
            if(tmp2 != nullptr)
                tmp->val += tmp2->val;
            carry = tmp->val/10;
            tmp->val %= 10;
            if(sumHead == nullptr){
                sumHead = tmp;
                cur = sumHead;
            }
            else{
                cur->next = tmp;
                cur = cur->next;
            }
            if(tmp1 != nullptr)
                tmp1 = tmp1->next;
            if(tmp2 != nullptr)
                tmp2= tmp2->next;
        }
        return sumHead;
    }
};