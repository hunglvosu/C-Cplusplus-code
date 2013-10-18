#include<stdio.h>
#include<stdlib.h>

struct stackElement {
 int id;
 struct stackElement *next;
};

typedef struct stackElement selement;
void push(int a, selement *shead);
selement *pop(selement *head);

selement *shead;

int main(){
 shead =  (selement*)malloc(sizeof(struct stackElement));
 shead->id = -1;
 push(2, shead);
 push(3, shead);
 push(4, shead);
 selement* elem = pop(shead);
 printf("popped element is : %d\n", elem->id);
}

void push(int a, selement *shead){
  selement *stop = shead->next;
  selement *temp = (selement*)malloc(sizeof(struct stackElement));
  temp->id = a;
  temp->next = stop;
  shead->next = temp;
}

selement *pop(selement *shead){
 if(shead->next == NULL){
  printf("stack is empty\n");
 }
 selement *elem = shead->next;
 selement *newhead = elem->next;
 shead->next = newhead;
 return elem;
}
