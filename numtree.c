#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 
typedef struct bst
{
        	 char item[10];
        	 struct bst *lchild, *rchild;
}BST;
 

void create();
BST * insert(char data[]);
BST * search(char key[]);
void preorder(BST * T);
void inorder(BST * T);
void postorder(BST *T);
BST * root;

int main (void)
{
        	 BST *p;
        	 char key[20];
			 char data[20];
			 int ch,option;
        	 root=NULL;
                    	do
        	 {
                    	 printf("\n1:Create\n2:Search\n3:Insert\n4:Preorder"\
                    	 "\n5:Inorder\n6:Postorder\n7:Exit");
                    	 printf("\n Please enter the choice:");
                    	 scanf("%d",&ch);
                    	 switch(ch)
                    	 {
                                
 
                                	 case 1:
                                            		create();
                                            	  break;
                                	 case 2:
                                            	  printf("\n Please enter the key to be found:");
                                            	  scanf("%s",&key);
                                	        	  p=search(key);
                                            	  if(p==NULL)
                                                        	 printf("\n Key not found");
                                            	  else
                                                        	 printf("\n Key found");
                                            	  break;
                                	 case 3:
                                            	  printf("\n Please enter the data to"\
                                            	  "be inserted");
 
                                            	  scanf("%s",&data);
                                            	  root=insert(data);
                                	        	  break;
 
                                	 case 4:
                                            	  preorder(root);
                                            	  break;
                                	 case 5:
                                            	  inorder(root);
                                            	  break;
                                	 case 6:
                                            	  postorder(root);
                                            	  break;
                                	 case 7:
                                            	  exit(0);
 
                    	 }   
printf("\nDo you want to continue yes=1/No=0)?");
scanf("%d",&option);
        	 }
        	 while(option==1);
        	 return 0;
 
}  
 

 
void create( )
{
        	 int n ,i;
			 char data[10];
        	 printf("\n Please enter the number of nodes:");
        	 scanf("%d",&n);
        	 for(i=0;i<n;i++)
        	 {
                    	 printf("\n Please enter the data:");
                    	 scanf("%s",&data);
                    	 root=insert(data);
        	 }
        	 
}
 


BST * insert(char data[]) {
	BST *temp;
	BST *cur = root; 
	BST *prev = NULL;
    temp = (BST *)malloc(sizeof(BST));
    strcpy(temp->item, data);
	
    temp->lchild = temp->rchild = NULL;
 		
    if (root == NULL)
        return temp;

   
    while (cur != NULL) {
        prev = cur;
        if (strcmp(data, cur->item) > 0)
            cur = cur->rchild;
        else
            cur = cur->lchild;
    }

    if (strcmp(data, prev->item) > 0)
        prev->rchild = temp;
    else
        prev->lchild = temp;

    return root;
}
 

BST * search(char key[]) {
    BST *T = root;
    while (T != NULL) {
        if (strcmp(key, T->item) == 0)
            return T;
        if (strcmp(key, T->item) > 0)
            T = T->rchild;
        else
            T = T->lchild;
    }
    return NULL;
}
 

void preorder(BST *T)
{
        	 if(T!=NULL)
        	 {
                    	 printf("%s\t",T->item);
                    	 preorder(T->lchild);
                    	 preorder(T->rchild);
        	 }
}
 
void inorder(BST *T) {
    if (T != NULL) {
        inorder(T->lchild);
        printf("%s\t", T->item);
        inorder(T->rchild);
    }
}

void postorder(BST *T)
{
        	 if(T!=NULL)
        	 {
                    	 postorder(T->lchild);
                    	 postorder(T->rchild);
                    	 printf("%s\t",T->item);
        	 }
}
 
/*
1:Create
2:Search
3:Insert
4:Preorder
5:Inorder
6:Postorder
7:Exit
 Please enter the choice:1

 Please enter the number of nodes:5

 Please enter the data:main_building

 Please enter the data:parking

 Please enter the data:hostel

 Please enter the data:workshop

 Please enter the data:library

Do you want to continue yes=1/No=0)?1

1:Create
2:Search
3:Insert
4:Preorder
5:Inorder
6:Postorder
7:Exit
 Please enter the choice:4
main_building   hostel  library parking workshop
Do you want to continue yes=1/No=0)?1

1:Create
2:Search
3:Insert
4:Preorder
5:Inorder
6:Postorder
7:Exit
 Please enter the choice:5
hostel  library main_building   parking workshop
Do you want to continue yes=1/No=0)?1

1:Create
2:Search
3:Insert
4:Preorder
5:Inorder
6:Postorder
7:Exit
 Please enter the choice:6
library hostel  workshop        parking main_building
Do you want to continue yes=1/No=0)?1

1:Create
2:Search
3:Insert
4:Preorder
5:Inorder
6:Postorder
7:Exit
 Please enter the choice:2

 Please enter the key to be found:workshop

 Key found
Do you want to continue yes=1/No=0)?0

Press Enter to return to Quincy...
*/

