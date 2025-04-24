/*
Reverse Linked List

Given the beginning of a singly linked list head, reverse the list, and return the new beginning of the list.

Example 1:

Input: head = [0,1,2,3]

Output: [3,2,1,0]

Example 2:

Input: head = []

Output: []

Constraints:

    0 <= The length of the list <= 1000.
    -1000 <= Node.val <= 1000
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *reversed { nullptr };
        ListNode *parent { nullptr };
        while (head) {
            if (!reversed) {
                reversed = new ListNode(head->val);
            } else {
                parent = new ListNode(head->val);
                parent->next = reversed;
                reversed = parent;
            }
            head = head->next;
        }
        return reversed;
    }
};