#include<stdio.h>
#include<stdlib.h>

typedef struct {
 int *x;
 int *y;
 int top;
 int index;
 int size;

}Stack;
void initStack(Stack *s, size_t size);
void push(int x, int y, Stack *s);
void pop(Stack *s, int *x, int *y);

int main(){
 Stack s;
 initStack(&s, 5);
 int i = 0;
 for(i = 1; i < 10; i ++){
  push(i,i, &s);
 }
 int a, b;
 while(s.top < s.index){
   pop(&s, &a, &b);
   printf("pop: %d\n", a);
 }
}

void initStack(Stack *s, size_t size){
 s->x = (int *) malloc(size*sizeof(int));
 s->y = (int *) malloc(size*sizeof(int));
 s->top = 0;
 s->index = 0;
 s->size = size;
}
void push(int x, int y, Stack *s){
 s->x[s->index] = x;
 s->y[s->index] = y;
 if(s->index == s->size-1){
   s->size *= 2;
   s->x =(int *)realloc(s->x, s->size*sizeof(int));
   s->y = (int *)realloc(s->y, s->size*sizeof(int));
 }
 s->index ++;

}
void pop(Stack *s, int *a, int *b){
  if(s->top < s->index ){ 
	*a = s->x[s->top];
	*b = s->y[s->top];
	s->top++;
  }else {
	printf("stack is empty\n");
  }
 } 
