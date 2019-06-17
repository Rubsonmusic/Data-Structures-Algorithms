/*
 * avl.cpp
 */

#ifndef AVL_CPP
#define AVL_CPP



/* TODO
 * Goal: To find the balance factor of an AVL tree
 *       balance factor = height of right sub-tree - height of left sub-tree
 * Return: (int) balance factor
 */
template <typename T, typename K>
int AVL<T,K>::bfactor() const
{
	this->fix_height();
	if(this->left_subtree() && this->right_subtree()){
		return this->right_subtree()->height()-this->left_subtree()->height();
	}
	else if(this->left_subtree() || this->right_subtree()){
		if(this->left_subtree()){
		    return -1-this->left_subtree()->height();
		   	}
	  	else{
	  		return this->right_subtree()->height()+1;
		 }
	}
	else
		return 0;
}


/* TODO
 * Goal: To rectify the height values of each node of of an AVL tree 
 */
template <typename T, typename K>
void AVL<T,K>::fix_height() const
{
    if(this->left_subtree() && this->right_subtree()){
    	AVL<T,K>* leftist=dynamic_cast<AVL<T,K>*>(this->root->left);
    	AVL<T,K>* rightist=dynamic_cast<AVL<T,K>*>(this->root->right);
    	leftist->fix_height();
    	rightist->fix_height();
    	this->root->bt_height=(leftist->root->bt_height>rightist->root->bt_height)?(leftist->root->bt_height+1):(rightist->root->bt_height+1);
    }
    else if(this->left_subtree() || this->right_subtree()){
    	if(this->left_subtree()){
    		AVL<T,K>* leftist=dynamic_cast<AVL<T,K>*>(this->root->left);
    		leftist->fix_height();
    		this->root->bt_height=leftist->root->bt_height+1;
    	}
    	else{
    		AVL<T,K>* rightist=dynamic_cast<AVL<T,K>*>(this->root->right);
    		rightist->fix_height();
    		this->root->bt_height=rightist->root->bt_height+1;
    	}
    }
    else{
    	this->root->bt_height=0;
    }
}


/* TODO
 * Goal: To perform a single left (anti-clocwise) rotation of the root 
 */
template <typename T, typename K>
void AVL<T,K>::rotate_left() 
{
    if(!this->right_subtree())
    	return;
    AVL<T,K>* b= dynamic_cast<AVL<T,K>*>(this->root->right);
    T tempvalue= this->root->value;
    K tempkey= this->root->key;
    this->root->key=b->root->key;
    this->root->value=b->root->value;
    b->root->value= tempvalue;
    b->root->key=tempkey;
    BT<T,K>* Tthree= b->root->right;
    b->root->right= b->root->left;
    b->root->left= this->root->left;
    this->root->left=this->root->right;
    this->root->right=Tthree;
}


/* TODO
 * Goal: To perform right (clockwise) rotation of the root 
 */
template <typename T, typename K>
void AVL<T,K>::rotate_right()
{
	if(!this->left_subtree())
	    return;
	AVL<T,K>* b= dynamic_cast<AVL<T,K>*>(this->root->left);
	T tempvalue= this->root->value;
	K tempkey= this->root->key;
	this->root->key=b->root->key;
	this->root->value=b->root->value;
	b->root->value= tempvalue;
	b->root->key=tempkey;
	BT<T,K>* Tone= b->root->left;
	b->root->left= b->root->right;
	b->root->right= this->root->right;
	this->root->right=this->root->left;
	this->root->left=Tone;
}

/* TODO
 * Goal: To balance an AVL tree 
 */
template <typename T, typename K>
void AVL<T,K>::balance()
{

	this->fix_height();

	AVL<T,K>* rite= dynamic_cast<AVL<T,K>*>(this->root->right);
	if(rite!=NULL){
		rite->balance();
	}

	this->fix_height();

	AVL<T,K>* let= dynamic_cast<AVL<T,K>*>(this->root->left);
	if(let!=NULL){
		let->balance();
	}

	this->fix_height();

     if(this->bfactor()==2){
    	 AVL<T,K>* r= dynamic_cast<AVL<T,K>*>(this->root->right);
    	 if(r->bfactor()==1){
    		 this->rotate_left();
    	 }
    	 else if(r->bfactor()==-1){
    		 r->rotate_right();
    		 this->rotate_left();
    	 }
     }
     else if(this->bfactor()==-2){

    	 AVL<T,K>* l= dynamic_cast<AVL<T,K>*>(this->root->left);
    	 if(l->bfactor()==-1){
    		 this->rotate_right();
    	 }
    	 else if(l->bfactor()==1){
    		 l->rotate_left();
    		 this->rotate_right();
    	 }
     }
}


/* TODO
 * Goal: To insert an item x with key k to AVL tree
 */
template <typename T, typename K>
void AVL<T,K>::insert(const T& x, const K& k)
{

	//check height increment, dependence on iterator, implement no insertion of duplicate
	if(this->root==NULL){
		this->root= new bt_node(x,k);
	}
	else if(k<this->root->key && this->left_subtree()==NULL){
		this->root->left= new AVL<T,K>;
		this->root->left->insert(x,k);
	}
	else if(k<this->root->key){
		this->root->left->insert(x,k);
	}
	else if(k>this->root->key && this->right_subtree()==NULL){
		this->root->right= new AVL<T,K>;
		this->root->right->insert(x,k);
	}
	else if(k>this->root->key){
		this->root->right->insert(x,k);
	}
     this->balance();
}



/* TODO
 * Goal: To remove an item with key k in AVL tree 
 */
template <typename T, typename K>
void AVL<T,K>::remove(const K& k)
{

	if(this->root==NULL)
			return;
		else if(k==this->root->key){
			if(this->left_subtree() && this->right_subtree()){
				BT<T,K>* min_node=this->root->right->find_min();
				AVL<T,K>* bst_min_node=dynamic_cast<AVL<T,K>*>(min_node);

				K tempKey=bst_min_node->root->key;
				T tempValue=bst_min_node->root->value;
				this->remove(bst_min_node->root->key);
				this->root->key= tempKey;
				this->root->value= tempValue;
				this->balance();//just added
				return;
			}
			else if(this->left_subtree()){
				AVL<T,K>* under_root= dynamic_cast<AVL<T,K>*>(this->root->left);

				K tempKey=under_root->root->key;
				T tempValue=under_root->root->value;
				this->remove(under_root->root->key);
				this->root->key= tempKey;
				this->root->value= tempValue;
				this->balance();//just added
				return;
			}
			else if(this->right_subtree()){
				BT<T,K>* min_node=this->root->right->find_min();
				AVL<T,K>* bst_min_node=dynamic_cast<AVL<T,K>*>(min_node);

				K tempKey=bst_min_node->root->key;
				T tempValue=bst_min_node->root->value;
				this->remove(bst_min_node->root->key);
				this->root->key= tempKey;
				this->root->value= tempValue;
				this->balance();//just added
				return;
			}

			else{
				delete this->root;
				this->root=NULL;

				return;
			}
		}
		else if(!this->search(k))
			return;
		else if(k<this->root->key){
				AVL<T,K>* under_root= dynamic_cast<AVL<T,K>*>(this->root->left);
			if(under_root->root->key==k){
				if(under_root->left_subtree() && under_root->right_subtree()){
					BT<T,K>* min_node=under_root->root->right->find_min();
					AVL<T,K>* bst_min_node=dynamic_cast<AVL<T,K>*>(min_node);

					K tempKey=bst_min_node->root->key;
					T tempValue=bst_min_node->root->value;
					under_root->remove(bst_min_node->root->key);
					under_root->root->key= tempKey;
					under_root->root->value= tempValue;
					this->balance();//just added
					return;
				}
				else if(under_root->left_subtree()|| under_root->right_subtree()){
					this->root->left=(under_root->left_subtree())?under_root->root->left:under_root->root->right;
					under_root->root->left=NULL; under_root->root->right=NULL;
					delete under_root;
					this->balance();//just added
					return;
				}
				else{
					this->root->left=NULL;
					delete under_root;
					this->balance();//just added
					return;
				}
			}
			else {
				this->root->left->remove(k);
				this->balance();//just added
				return;
			}
		}
		else if(k>this->root->key){
			AVL<T,K>* under_root= dynamic_cast<AVL<T,K>*>(this->root->right);
			if(under_root->root->key==k){
				if(under_root->left_subtree() && under_root->right_subtree()){
					BT<T,K>* min_node=under_root->root->right->find_min();
					AVL<T,K>* bst_min_node=dynamic_cast<AVL<T,K>*>(min_node);

					K tempKey=bst_min_node->root->key;
					T tempValue=bst_min_node->root->value;
					under_root->remove(bst_min_node->root->key);
					under_root->root->key= tempKey;
					under_root->root->value= tempValue;
					this->balance();//just added
					return;
				}
				else if(under_root->left_subtree()|| under_root->right_subtree()){
					this->root->right=(under_root->left_subtree())?under_root->root->left:under_root->root->right;
					under_root->root->left=NULL; under_root->root->right=NULL;
					delete under_root;
					this->balance();//just added
					return;
				}
				else{
					this->root->right=NULL;
					under_root->remove(k);
					this->balance();//just added
					return;
				}
			}
			else {
				this->root->right->remove(k);
				this->balance();//just added
				return;
			}
		}
	this->balance();
}



#endif /* AVL_CPP */
