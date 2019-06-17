/*
 * bst.cpp
 *
 */

#ifndef BST_CPP
#define BST_CPP


/* TODO
 * Goal: To search for an item x with key k from the BST tree
 * Return: A pointer to the subtree whose root node contains the item if found,
 *         otherwise a NULL pointer.
 */
template <typename T, typename K>
BT<T,K>* BST<T,K>::search(const K& k)				//not checked
{
    if(this->root->key == k)
    	return this;
    else if(this->left_subtree()!=NULL && k<this->root->key)
    	return this->left_subtree()->search(k);
    else if(this->right_subtree()!=NULL && k>this->root->key)
    	return this->right_subtree()->search(k);
    else
    	return NULL;
}


/* TODO
 * Goal: To find the minimum node stored in a BST tree.
 * Return: A pointer to the subtree whose root node contains the minimum key
 */
template <typename T, typename K>					//not checked
BT<T,K>* BST<T,K>::find_min()
{
    if(this->left_subtree()==NULL){
    	BT<T,K>* c= &(*this);
    	return c;
    }
    else
    	return this->root->left->find_min();
}


/* TODO
 * Goal: To insert an item x with key k to a BST tree 
 */
template <typename T, typename K>
void BST<T,K>::insert(const T& x, const K& k)
{
	//check height increment, dependence on iterator, implement no insertion of duplicate
	if(this->root==NULL){
		this->root= new bt_node(x,k);
	}
	else if(k<this->root->key && this->left_subtree()==NULL){
		this->root->left= new BST<T,K>;
		this->root->left->insert(x,k);
	}
	else if(k<this->root->key){
		this->root->left->insert(x,k);
	}
	else if(k>this->root->key && this->right_subtree()==NULL){
		this->root->right= new BST<T,K>;
		this->root->right->insert(x,k);
	}
	else if(k>this->root->key){
		this->root->right->insert(x,k);
	}
}


/* TODO
 * Goal: To remove an item with key k in a BST tree 
 */
template <typename T, typename K>
void BST<T,K>::remove(const K& k)
{    
	if(this->root==NULL)
		return;
	else if(k==this->root->key){
		if(this->left_subtree() && this->right_subtree()){
			BT<T,K>* min_node=this->root->right->find_min();
			BST<T,K>* bst_min_node=dynamic_cast<BST<T,K>*>(min_node);

			K tempKey=bst_min_node->root->key;
			T tempValue=bst_min_node->root->value;
			this->remove(bst_min_node->root->key);
			this->root->key= tempKey;
			this->root->value= tempValue;
			return;
		}
		else if(this->left_subtree()){
			BST<T,K>* under_root= dynamic_cast<BST<T,K>*>(this->root->left);

			K tempKey=under_root->root->key;
			T tempValue=under_root->root->value;
			this->remove(under_root->root->key);
			this->root->key= tempKey;
			this->root->value= tempValue;
			return;
		}
		else if(this->right_subtree()){
			BT<T,K>* min_node=this->root->right->find_min();
			BST<T,K>* bst_min_node=dynamic_cast<BST<T,K>*>(min_node);

			K tempKey=bst_min_node->root->key;
			T tempValue=bst_min_node->root->value;
			this->remove(bst_min_node->root->key);
			this->root->key= tempKey;
			this->root->value= tempValue;
			return;
		}

		else{
			delete this->root;
			this->root=NULL;
			return;
		}
	}
	else if(!search(k))
		return;
	else if(k<this->root->key){
			BST<T,K>* under_root= dynamic_cast<BST<T,K>*>(this->root->left);
		if(under_root->root->key==k){
			if(under_root->left_subtree() && under_root->right_subtree()){
				BT<T,K>* min_node=under_root->root->right->find_min();
				BST<T,K>* bst_min_node=dynamic_cast<BST<T,K>*>(min_node);

				K tempKey=bst_min_node->root->key;
				T tempValue=bst_min_node->root->value;
				under_root->remove(bst_min_node->root->key);
				under_root->root->key= tempKey;
				under_root->root->value= tempValue;
				return;
			}
			else if(under_root->left_subtree()|| under_root->right_subtree()){
				this->root->left=(under_root->left_subtree())?under_root->root->left:under_root->root->right;
				under_root->root->left=NULL; under_root->root->right=NULL;
				delete under_root;
				return;
			}
			else{
				this->root->left=NULL;
				delete under_root;
				return;
			}
		}
		else {
			this->root->left->remove(k);
			return;
		}
	}
	else if(k>this->root->key){
		BST<T,K>* under_root= dynamic_cast<BST<T,K>*>(this->root->right);
		if(under_root->root->key==k){
			if(under_root->left_subtree() && under_root->right_subtree()){
				BT<T,K>* min_node=under_root->root->right->find_min();
				BST<T,K>* bst_min_node=dynamic_cast<BST<T,K>*>(min_node);

				K tempKey=bst_min_node->root->key;
				T tempValue=bst_min_node->root->value;
				under_root->remove(bst_min_node->root->key);
				under_root->root->key= tempKey;
				under_root->root->value= tempValue;
				return;
			}
			else if(under_root->left_subtree()|| under_root->right_subtree()){
				this->root->right=(under_root->left_subtree())?under_root->root->left:under_root->root->right;
				under_root->root->left=NULL; under_root->root->right=NULL;
				delete under_root;
				return;
			}
			else{
				this->root->right=NULL;
				under_root->remove(k);
				return;
			}
		}
		else {
			this->root->right->remove(k);
			return;
		}
	}



}


/* TODO
 * Goal: Clear the node stack and set current pointer to the root 
 */
template<typename T, typename K>
void BST<T,K>::iterator_init()
{
    this->current=this->root;
    while(!this->istack.empty()){
    	this->istack.pop();
    }
    //this->istack.push(this->current);
}


/* TODO
 * Goal: Check whether the next smallest node exists 
 */
template<typename T, typename K>
bool BST<T,K>::iterator_end()
{
	return (this->current==NULL && this->istack.empty());
}


/* TODO
 * Goal: Return the value of next smallest node from the tree 
 */
template<typename T, typename K>
T& BST<T,K>::iterator_next()
{
	while(this->current!=NULL){
		this->istack.push(this->current);
		if(this->current->left==NULL){
			this->current=NULL;
			break;
		}
		else{
			BST<T,K>* leftist=dynamic_cast<BST<T,K>*>(this->current->left);
			this->current=leftist->root;
		}
	}
	if(this->current==NULL && this->istack.empty()){
		return this->root->value;
	}
	T& return_value= this->istack.top()->value;
	BST<T,K>* rightist=dynamic_cast<BST<T,K>*>(this->istack.top()->right);
	if(rightist!=NULL)
		this->current=rightist->root;
	else
		this->current=NULL;

	this->istack.pop();
	return return_value;
}


#endif /* BST_CPP */
