#include<stdio.h>
int a[10] = {1,2,3,4,5,3,22,9,7,8};
struct llnode{
 int val;
 struct llnode *next; 
};
typedef struct llnode node;
node *head;

int main() {
head = (node *)malloc(sizeof (node));
head->val = -1;
head->next = NULL;
node *inode;
inode = head;
int i = 0;
for (i = 0; i < 10; i++) {
	node *temp;
	temp = (node *)malloc(sizeof(node));
	temp->val = a[i];
	temp->next = NULL;
	inode->next = temp;
	inode = inode->next;
			
 }
inode = head->next;
while (inode != NULL){
	printf("%d\n",inode->val);
	inode = inode->next;
 } 
}
