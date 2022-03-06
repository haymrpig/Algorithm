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
        int carry = 0;
        ListNode* ans = NULL;
        ListNode* cur = NULL;
        ListNode* temp;
        while(l1!=NULL || l2!=NULL){
            int sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            
            carry = sum >=10 ? sum/10:0;
            sum = sum%10;
            temp = new ListNode(sum);
            
            if(ans==NULL) ans = temp;
            else cur->next = temp;
            
            cur = temp;
            
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
        if(carry!=0){
            temp = new ListNode(carry);
            cur->next = temp;
        }
        
        return ans;
    }
};