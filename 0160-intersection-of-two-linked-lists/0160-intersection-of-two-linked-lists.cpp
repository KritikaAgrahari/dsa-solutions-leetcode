/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Two pointers starting at the heads of both lists
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        // Traverse until they meet or both reach null
        while (ptrA != ptrB) {
            // Move to next node, or switch to the head of the other list
            ptrA = (ptrA != nullptr) ? ptrA->next : headB;
            ptrB = (ptrB != nullptr) ? ptrB->next : headA;
        }

        // Either they meet at intersection or both are null
        return ptrA;
        
    }
};