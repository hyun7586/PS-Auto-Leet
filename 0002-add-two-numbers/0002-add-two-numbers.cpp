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
        // result: the pointer representing the first node of the result list
        // ptr: the pointer iterating the result list
        ListNode* result=new ListNode(0);
        ListNode* ptr = result;
        int carry=0;

        while(l1!=nullptr && l2!=nullptr){
            int temp = l1->val + l2->val + ptr->val;
            ptr->val=temp%10;
            carry=temp/10;

            l1=l1->next;
            l2=l2->next;

            if(carry!=0 || l1!=nullptr || l2!=nullptr){
                ptr->next=new ListNode(carry);
                ptr=ptr->next;
            }
        }

        while(l1!=nullptr){
            int temp = l1->val+ptr->val;
            ptr->val=temp%10;
            carry=temp/10;

            l1=l1->next;

            if(carry!=0 || l1!=nullptr){
                ptr->next = new ListNode(carry);
                ptr=ptr->next;
            }
        } 

        while(l2!=nullptr){
            int temp = l2->val+ptr->val;
            ptr->val=temp%10;
            carry=temp/10;

            l2=l2->next;

            if(carry!=0 || l2!=nullptr){
                ptr->next = new ListNode(carry);
                ptr=ptr->next;
            }
        } 

        return result;
    }
};