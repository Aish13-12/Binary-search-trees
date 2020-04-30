struct node  //Defining the node structure
{
	int key;
	struct node*parent;
	struct node*right;
	struct node*left;
};

void insert(struct node**head,int key11);
void printtreepre(struct node*currentno);
void printtreein(struct node*currentno);
void printtreepost(struct node*currentno);
void printpre(struct node**head);
void printin(struct node**head);
void printin(struct node**head);
struct node *deletetree(struct node*head,int key1);
struct node *find(struct node*head,int key1);
void imbalance(struct node*head,int key1);



struct node *inserttree(struct node*fipa,int key1)//Finding the node to which new node will be attached
{
	struct node*prev=fipa;
	if(key1>fipa->key)
	fipa=fipa->right;
	else
	fipa=fipa->left;
	if(fipa==NULL)
	return prev;
	else
	inserttree(fipa,key1);
}
void insert(struct node**head,int key11)//To insert a node with a given key in a given tree
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->key=key11;
	temp->left=NULL;
	temp->right=NULL;
	temp->parent=NULL;
	if(*head==NULL)
	*head=temp;
	else
	{
		struct node*temp1=*head;
		struct node*temp2=inserttree(temp1,key11);
		if(key11>temp2->key)
		{
			temp2->right=temp;//Attaching the new node
			temp->parent=temp2;
		}	
		
		else
		{
			temp2->left=temp;
			temp->parent=temp2;
		}
	}
	printf("True");
}

//Preorder-first printing the parent and then its children.
void printtreepre(struct node*currentno)//To print the sub-tree with a given node in preorder
{
	if(currentno==NULL)
	return;
	else
	{
		printf("%d ",currentno->key);
		struct node*templ=currentno;
		struct node*tempr=currentno;
		templ=templ->left;
		tempr=tempr->right;
		if(tempr!=NULL&&templ!=NULL)
		{
			printtreepre(templ);
			printtreepre(tempr);
		}
		else if(tempr!=NULL&&templ==NULL)
		printtreepre(tempr);
		else if(tempr==NULL&&templ!=NULL)
		printtreepre(templ);	
		else
		return;
		
	}
}

//Inorder-first printing the left child,then the parent and then the right child
void printtreein(struct node*currentno)//To print the sub-tree with a given node in inorder
{
	if(currentno==NULL)
	return;
	else 
	{
		struct node*templ=currentno->left;
		struct node*tempr=currentno->right;
		if(tempr!=NULL&&templ!=NULL)
		{
			printtreein(templ);
			printf("%d ",currentno->key);
			printtreein(tempr);
		}
		else if(tempr!=NULL&&templ==NULL)
		{
			printf("%d ",currentno->key);
			printtreein(tempr);
		}	
		
		else if(tempr==NULL&&templ!=NULL)
		{
			printtreein(templ);
			printf("%d ",currentno->key);
		}
		else
		printf("%d ",currentno->key);
	}
}

//Postorder-first printing the childrena and then the parent
void printtreepost(struct node*currentno)//To print the sub-tree with a given node in postorder
{
	if(currentno==NULL)
	return;
	else
	{
		struct node*templ=currentno->left;
		struct node*tempr=currentno->right;
		if(tempr!=NULL&&templ!=NULL)
		{
			printtreepost(templ);
			printtreepost(tempr);
			printf("%d ",currentno->key);
		}
		else if(tempr!=NULL&&templ==NULL)
		{
			printtreepost(tempr);
			printf("%d ",currentno->key);
		}
		else if(tempr==NULL&&templ!=NULL)
		{
			printtreepost(templ);
			printf("%d ",currentno->key);
		}
		else
		printf("%d ",currentno->key);
	}
}							
				
		
//To print the whole tree in preorder,inorder,postorder
void printpre(struct node**head)
{
	printtreepre(*head);
}		

void printin(struct node**head)
{
	printtreein(*head);
}		

void printpost(struct node**head)
{
	printtreepost(*head);
}	

//To find node with the least key in a sub-tree with a given node as the head
struct node *minkey(struct node*temp)
{
	struct node*present=temp;
	
	while(present!=NULL&&present->left!=NULL)
	present=present->left;
	return present;
}	
		
	
		
//To delete a node with a given key		
struct node *deletetree(struct node*head,int key1)
{
	if(head==NULL)
	{
		printf("False");
		return head;
		
	}	
	
	
	if(key1>head->key)//Continue to find the node
	head->right=deletetree(head->right,key1);
	else if(key1<head->key)
	head->left=deletetree(head->left,key1);
	else
	{
		//On finding the needed node
		printf("True");
		//If the node has atmost only one child
		if(head->left==NULL)
		{
			struct node*temp1=head->right;
			free(head);
			return temp1;
		}	
		
		else if(head->right==NULL)
		{
			struct node*temp1=head->left;
			return temp1;
			free(head);
		}	
		//If the node has two children
		else 
		{
			struct node*temp1=minkey(head->right);//Replacing the deleted node with the least element in its right subtree
			head->key=temp1->key;
			head->right=deletetree(head->right,temp1->key);
		}
		return head;
		
	}
}			
			
int ri=0;
int le=0;			
struct node *find(struct node*head,int key1)//To find the node with a given key and it depth
{
	
	if(head==NULL)
	{
		printf("False");
		return head;
	}
	if(key1>head->key)
	{
		ri++;
		find(head->right,key1);
	}	
	
	else if(key1<head->key)
	{
		le++;
	    find(head->left,key1);
	}	
	
	else
	{
		
		printf("True,");
		printf("Depth: %d",ri+le);
		return head;
	
	}
}				

int ri2=0;
int le2=0;	
void numnodes(struct node*currentno)//Returns the number of nodes attached to a particular node
{
	if(currentno==NULL)
	return;
	else
	{
		struct node*temp1=currentno->left;
		struct node*temp2=currentno->right;
		numnodes(temp1);
		if(temp1!=NULL)
		ri2++;
		numnodes(temp2);
		if(temp2!=NULL)
		le2++;
	}
}

void imbalance(struct node*head,int key1)
{
	ri=0;
	le=0;
	struct node*currentno=find(head,key1);//Finding the required node
	printf("%c[2K", 27);//Deleting the current line in the console(As find prints depth)
    printf("\r");//Returning to the starting of the line
	if(currentno==NULL)
	{
		printf("False");
		return;
	}
	else
	{
			
	   numnodes(currentno->left);//Number of nodes in its left sub-tree
	   int left=ri2+le2;
	   if(currentno->left!=NULL)
	   left=left+1;
	   ri2=0;
	   le2=0;
	   numnodes(currentno->right);//Number of nodes in its right subtree
	   int right=ri2+le2;
	   if(currentno->right!=NULL)
	   right=right+1;
	   if(left>right)
	   printf("Imbalance: %d",left-right);
	   else
	   printf("Imbalance: %d",right-left);
	  } 
	  ri2=0;
	  le2=0;
	  ri=0;
	  le=0;
}	




		
					
			
	
	
	
	
	
				
		
		
	
	
	
	
	
	
	
	
	
		
		
