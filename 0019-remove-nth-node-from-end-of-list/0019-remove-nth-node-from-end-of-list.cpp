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
        // the number of nodes
        int N = 0;
        for (ListNode* ptr = head; ptr; ptr = ptr->next)    N += 1;


        int index = N - n;

        if (N == n) {
            head = head->next;
        }else{
            ListNode* current = head;
            ListNode* prev = head;

            for (int i = 0; i < index; i++) {
                prev = current;
                current = current->next;
            }

            prev->next = current->next;
        }

        return head;
    }
};