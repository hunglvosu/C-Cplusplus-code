#include<stdio.h>
#define MAX 10
int a[MAX] = {1,6,5,34,3,2,9,8,6,7};
struct cllnode {
 int id;
 struct cllnode *next;
};

typedef struct cllnode node;
node *head;

int main(){
head = (node *)malloc(sizeof(node));
head->id = -1;
head->next = NULL;
node *inode;
inode = head;
int i = 0;
for (i = 0; i < MAX; i ++){
	node *temp;
	temp = (node *)malloc(sizeof(node));
	temp->id = a[i];
	temp->next = NULL;
	inode->next = temp;
	inode = inode->next;	 
 }
inode->next = head->next;
i = 0;
inode = head->next;
while ( i < MAX+5){
	printf("%d\n",inode->id);
	inode = inode->next;
	i++;
	if (i == MAX){
 		printf("circularly retrieve\n");
 }
}
}
