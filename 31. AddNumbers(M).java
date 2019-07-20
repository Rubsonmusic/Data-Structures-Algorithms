// https://leetcode.com/problems/add-two-numbers/


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void add(ListNode a, ListNode b, int carry, ListNode ret){
        if(a==null && b==null){
            if(carry!=0){ret.next = new ListNode(carry);}
        }
        else if(a==null || b==null){
            a = (a==null) ? b: a;
            ret.next = new ListNode((a.val+carry)%10);
            add(a.next, null, (a.val+carry)/10, ret.next);
        }
        else{
            int sum = a.val + b.val + carry;
            ret.next = new ListNode(sum%10);
            add(a.next, b.next, sum/10, ret.next);
        }
    }
    
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode rv = new ListNode(0);
        add(l1, l2, 0, rv);
        return rv.next;
    }
}
