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
        int N = 0;
        for (ListNode* ptr = head; ptr; ptr = ptr->next)
            N += 1;

        // the index which is going to removed
        int count = N - n;

        if (N == n) {
            head = head->next;
        }

        if (count != 0) {
            ListNode* current = head;
            ListNode* prev = head;
            for (int i = 0; i < count; i++) {
                prev = current;
                current = current->next;
                cout << prev->val << " " << current->val << '\n';
            }

            prev->next = current->next;
            current->next = NULL;
        }

        return head;
    }
};