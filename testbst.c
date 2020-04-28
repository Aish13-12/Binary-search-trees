#include <stdio.h>
#include <stdlib.h>
#include "bstfun.h"

int main()
{
	struct node*head=NULL;
	int numcomm=0;
	
	scanf("%d",&numcomm);
	int arr[2*numcomm];
	int i;
	
	for(i=0;i<2*numcomm;)
	{
		scanf("%d",&arr[i]);
		switch(arr[i])
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
			case 4:
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
	struct node*currentno=NULL;		          
	int j;
	for(j=0;j<2*numcomm;)
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
			   printf("\nPreorder:");
			   printpre(&head);
			   printf("\nInorder:");
			   printin(&head);
			   printf("\nPostorder:");
			   printpost(&head);
			   printf("\n");
			   break;
			case 5:
			   ri=0;
			   le=0;
			   currentno=find(head,arr[j+1]);
			   printf("\nPreorder:");
			   printtreepre(currentno);
			   printf("\nInorder:");
			   printtreein(currentno);
			   printf("\nPostorder:");
			   printtreepost(currentno);
			   printf("\n");
			   break;
			case 6:    
			   imbalance(head,arr[j+1]);
			   break;
			default:exit(EXIT_SUCCESS);
		}
		j=j+2;
	}		
			
			       
			   		
			
	
		
	return 0;
}			
			
			
	
