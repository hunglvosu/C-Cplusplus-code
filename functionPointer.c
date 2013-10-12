#include<stdio.h>

int add(int x, int y);
int main(){
 int (*fp)(int x, int y);
 fp = &add;
 printf("Sum of 2 and 3 by function pointer is %d\n",(*fp)(2,3));

}
int add(int x, int y){
 return x+y;
}
