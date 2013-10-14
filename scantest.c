#include<stdio.h>
//when input string by pointer without memory allocation
//it could create a problem for you.
// See below examples

int main(){
 printf("Input string. This example will work fine\n");
 char x[10];
 char y[10];
 scanf("%s",x);
 scanf("%s",y);
 printf("%s----%s\n", x,y);
 printf("Input string. This example may not work!\n");
 char *a, *b; //that due to pointers is not allocated memory
 scanf("%s",a);
 scanf("%s",b);
 printf("%s----%s\n", a, b);
}
