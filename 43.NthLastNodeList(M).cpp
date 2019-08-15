// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// O(1) space, O(n) time
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {        
        int i = 1;
        ListNode* lead = head;
        ListNode* follow = NULL;
        
        while(lead->next!=NULL){            
            i++;
            if(follow!=NULL)
                follow = follow->next;
            lead = lead->next;
            
            if(i==n+1) follow = head;
        }
        
        if(follow == NULL){
            return head->next;
        }
        
        if(follow->next != NULL){
            follow->next = follow->next->next;
        }
        
        return head;
    }
};
