// https://leetcode.com/problems/linked-list-cycle/

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
    bool hasCycle(ListNode *head) {
        int count = 0;
        ListNode* minptr = head;
        ListNode* maxptr = head;
        while(head != NULL){
            minptr = min(minptr, head->next);
			maxptr = max(maxptr, head->next);
			count++;
			if (maxptr < minptr + 2*count)
				return true;
            head = head->next;
        }
		return false;
    }
};
