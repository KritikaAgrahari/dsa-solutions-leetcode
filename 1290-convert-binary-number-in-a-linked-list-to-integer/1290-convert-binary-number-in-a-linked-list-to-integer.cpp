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
    int getDecimalValue(ListNode* head) {
        //  int result = 0;
        // while (head) {
        //     result = result * 2 + head->val; // Shift left and add the current node's value
        //     head = head->next; // Move to the next node
        // }
        // return result;

        int result = 0;
while (head) {
    result = (result << 1) | head->val;  // Left shift and bitwise OR
    head = head->next;
}
return result;

        
    }
};