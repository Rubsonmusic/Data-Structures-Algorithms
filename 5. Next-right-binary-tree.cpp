// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node* leftmost = root;
		Node* previous = NULL;
		Node* i = root;
		while(leftmost != NULL){
						
			while(i != NULL){
				
				//Handles 'previous' if its not NULL
				if (previous){
					if(i->left)
						previous->next = i->left;
					else if (i->right)
						previous->next = i->right;
					else{
						i = i->next;
						continue;
					}
				}
				
				//Updates 'previous', and connects i's children
				if(i->left and i->right){
					i->left->next = i->right;
					previous = i->right;
				}
				else if (i->left or i->right)
					previous = (i->left) ? i->left : i->right;
				
				//Updates i
				i = i->next;
					
			}
			previous = NULL;
			//at this point both i and previous are NULL
		    
            // initialize i
            if(leftmost->left){
                i = leftmost->left;
                leftmost = leftmost->left;
            }
            else if(leftmost->right){
                i = leftmost->right;
                leftmost = leftmost->right;
            }
            else
                leftmost = leftmost->next;
			
		}
		return root;
    }
};
