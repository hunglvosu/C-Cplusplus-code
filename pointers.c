#include<stdio.h>

int main() {
int a[10] = {1,2,3,4,5,6,3,2,9,7};
int *p = a;
int i = 0;
for (i =0; i < 10; i++){
 	printf("%d\n",*(p+i)); 
 	}	
}
