#include <stdio.h>
#include <stdlib.h>
#include "bstfun.h"//Including the functions in the form of a header file 

int main()
{
	struct node*head=NULL;
	int numcomm=0;
	
	scanf("%d",&numcomm);//To hold the number of commands to be executed
	int arr[2*numcomm];//To hold the index of the command and the key value
	int i;
	
	for(i=0;i<2*numcomm;)
	{
		scanf("%d",&arr[i]);
		switch(arr[i])//According to the index entered, conditions on key
		{
			case 1:
			   scanf("%d",&arr[i+1]);
			   i=i+2;
			   break;
			case 2:
			   scanf("%d",&arr[i+1]);
			   i=i+2;
			   break;
			case 3:
			   scanf("%d",&arr[i+1]);
			   i=i+2;
			   break;
			case 4://As index 4 is printing the whole tree, no key is entered
			   arr[i+1]=0;
			   i=i+2;
			   break;
			case 5:
			   scanf("%d",&arr[i+1]);
			   i=i+2;
			   break;
			case 6:
			   scanf("%d",&arr[i+1]);
			   i=i+2;
			   break;
			 default:exit(EXIT_FAILURE);
		}
	}		  
	printf("\n"); 
	struct node*currentno=NULL;		          
	int j;
	for(j=0;j<2*numcomm;)//Reading the array
	{
		switch(arr[j])
		{
			case 1:
			  insert(&head,arr[j+1]);
			  break;
			case 2:
			  deletetree(head,arr[j+1]);
			  break;
			case 3:
			  find(head,arr[j+1]);
			  break;
			case 4:
			   printf("Inorder:");
			   printin(&head);
			   printf("\nPreorder:");
			   printpre(&head);
			   
			   printf("\nPostorder:");
			   printpost(&head);
			   
			   break;
			case 5:
			   ri=0;
			   le=0;
			   currentno=find1(head,arr[j+1]);//finding the needed node to print the sub-tree
			   
			   printf("Inorder:");
			   printtreein(currentno);
			   printf("\nPreorder:");
			   printtreepre(currentno);
			   
			   printf("\nPostorder:");
			   printtreepost(currentno);
			   
			   break;
			case 6:    
			   imbalance(head,arr[j+1]);
			   break;
			default:exit(EXIT_SUCCESS);
		}
		j=j+2;
		printf("\n");
	}		
			
			       
			   		
			
	
		
	return 0;
}			
			
			
	
