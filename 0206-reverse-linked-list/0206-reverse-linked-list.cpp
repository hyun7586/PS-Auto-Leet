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
    ListNode* reverseList(ListNode* head) {
        // if n==0 || n==1
        if(head==NULL || head->next==NULL)  return head;

        ListNode* prev_node = head;
        ListNode* current_node = head->next;
        ListNode* temp;

        // iteration until current_node==NULL
        head->next=NULL;
        while(current_node){
            temp=current_node->next;
            current_node->next=prev_node;

            prev_node=current_node;
            current_node=temp;
        }

        return prev_node;
    }
};