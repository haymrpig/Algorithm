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
        ListNode* root = new ListNode();
        root->next = head;
        int pos = 1;
        ListNode* pre = root;
        while(pos++<left) pre=pre->next;
        
        ListNode* p = pre->next;
        while(pos++<=right){
            ListNode *temp = pre->next;
            pre->next = p->next;
            p->next = pre->next->next;
            pre->next->next = temp;
        }
        return root->next;
    }
};