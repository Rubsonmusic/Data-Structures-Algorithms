/*
 * bt.cpp
 *
 */

#ifndef BT_CPP
#define BT_CPP


/* TODO
 * Goal: Do preorder traversal on the tree
 * Remark: print both value and key fields of each node
 */
template <typename T, typename K>
void BT<T,K>::preorder_traversal() const									//spacing not correct
{
	if(!is_empty()){
		cout<<"Key: "<<root->key<<'\t'<<"Value: "<<root->value<<endl;
		if(left_subtree()!=NULL)
			left_subtree()->preorder_traversal();

		if(right_subtree()!=NULL)
			right_subtree()->preorder_traversal();
	}
}


#endif /* BT_CPP */
